static const char gVertexShader[] = 
    "attribute vec4 vPosition;\n"
	"uniform mat4 Projection;\n"
	"uniform mat4 Model;\n"
    "void main() {\n"
    "  gl_Position = Projection * Model * vPosition;\n"
    "}\n";

static const char gFragmentShader[] =
	//"precision mediump float;\n"
    "uniform vec3 fragColor;\n"
    "void main() {\n"
    "  gl_FragColor = vec4(fragColor, 1.0);\n"
    "}\n";