// This code is built from the Camera Ribbon example by James George, as well as the Alpha Masking Shader example.  I've added my own custom tweaks to these.

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    
    girlImg.load("girlsq.jpg");
    girlColorImg.load("girlColor2.jpg");
    
    int width = girlImg.getWidth();
    int height = girlImg.getHeight();
    
    maskFbo.allocate(width,height);
    fbo.allocate(width,height);

    
#ifdef TARGET_OPENGLES
    shader.load("shaders_gles/alphamask.vert","shaders_gles/alphamask.frag");
#else
    if(ofIsGLProgrammableRenderer()){
        string vertex = "#version 150\n\
        \n\
        uniform mat4 projectionMatrix;\n\
        uniform mat4 modelViewMatrix;\n\
        uniform mat4 modelViewProjectionMatrix;\n\
        \n\
        \n\
        in vec4  position;\n\
        in vec2  texcoord;\n\
        \n\
        out vec2 texCoordVarying;\n\
        \n\
        void main()\n\
        {\n\
        texCoordVarying = texcoord;\
        gl_Position = modelViewProjectionMatrix * position;\n\
        }";
        string fragment = "#version 150\n\
        \n\
        uniform sampler2DRect tex0;\
        uniform sampler2DRect maskTex;\
        in vec2 texCoordVarying;\n\
        \
        out vec4 fragColor;\n\
        void main (void){\
        vec2 pos = texCoordVarying;\
        \
        vec3 src = texture(tex0, pos).rgb;\
        float mask = texture(maskTex, pos).r;\
        \
        fragColor = vec4( src , mask);\
        }";
        shader.setupShaderFromSource(GL_VERTEX_SHADER, vertex);
        shader.setupShaderFromSource(GL_FRAGMENT_SHADER, fragment);
        shader.bindDefaults();
        shader.linkProgram();
    }else{
        string shaderProgram = "#version 120\n \
        #extension GL_ARB_texture_rectangle : enable\n \
        \
        uniform sampler2DRect tex0;\
        uniform sampler2DRect maskTex;\
        \
        void main (void){\
        vec2 pos = gl_TexCoord[0].st;\
        \
        vec3 src = texture2DRect(tex0, pos).rgb;\
        float mask = texture2DRect(maskTex, pos).r;\
        \
        gl_FragColor = vec4( src , mask);\
        }";
        shader.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderProgram);
        shader.linkProgram();
    }
#endif
    
    //clear the fbos of junk
    maskFbo.begin();
    ofClear(0,0,0,255);
    maskFbo.end();
    
    fbo.begin();
    ofClear(0,0,0,255);
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //ribbon
    ofVec3f sumOfAllPoints(0,0,0);
    for(unsigned int i = 0; i < points.size(); i++){
        points[i].z -= 4;
        sumOfAllPoints += points[i];
    }
    center = sumOfAllPoints / points.size();
    
    //mask that holds the ribbon mesh.
    //it's not clearing, which is what gives it the watery effect
    maskFbo.begin();
    vboMesh.draw();
    maskFbo.end();
    
    //shader masking happens here
    fbo.begin();
    //everthing gets an alpha mask set to 0 in order to make it transparent by default to start
    ofClear(0, 0, 0, 0);
    
    shader.begin();
    //shader must come before drawing the girl background image
    shader.setUniformTexture("maskTex", maskFbo.getTexture(), 1 );
    girlColorImg.draw(0,0);
    shader.end();
    fbo.end();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255,255);
    girlImg.draw(0,0);
    fbo.draw(0,0);
    
    //ribbon
    //ofSetColor(0);
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    for(unsigned int i = 1; i < points.size(); i++){
        
        //find this point and the next point
        ofVec3f thisPoint = points[i-1];
        ofVec3f nextPoint = points[i];
        
        //get the direction from one to the next.
        //the ribbon should fan out from this direction
        ofVec3f direction = (nextPoint - thisPoint);
        
        //get the distance from one point to the next
        float distance = direction.length();
        
        //get the normalized direction. normalized vectors always have a length of one
        //and are really useful for representing directions as opposed to something with length
        ofVec3f unitDirection = direction.getNormalized();
        
        //find both directions to the left and to the right
        ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
        ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));
        
        //use the map function to determine the distance.
        //the longer the distance, the narrower the line.
        //this makes it look a bit like brush strokes
        float thickness = ofMap(distance, 0, 60, 20, 2, true);
        
        //calculate the points to the left and to the right
        //by extending the current point in the direction of left/right by the length
        ofVec3f leftPoint = thisPoint+toTheLeft*thickness;
        ofVec3f rightPoint = thisPoint+toTheRight*thickness;
        
        //add these points to the triangle strip
        mesh.addVertex(ofVec3f(leftPoint.x, leftPoint.y, leftPoint.z));
        mesh.addVertex(ofVec3f(rightPoint.x, rightPoint.y, rightPoint.z));
    }
    
    //end the shape
    vboMesh = mesh;
//    
    girlImg.draw(0,0);
    fbo.draw(0,0);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    maskFbo.begin();
    ofClear(0,0,0,255);
    maskFbo.end();


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    //ribbon
    ofVec3f mousePoint(x,y,0);
    points.push_back(mousePoint);
    

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
