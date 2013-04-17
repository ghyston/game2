static const char gVertexShader[] = 
    "attribute vec4 vPosition;\n"
	"uniform mat4 Projection;\n"
    "void main() {\n"
    "  gl_Position = Projection * vPosition;\n"
    "}\n";

static const char gFragmentShader[] = 
    "precision mediump float;\n"
    "void main() {\n"
    "  gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
    "}\n";