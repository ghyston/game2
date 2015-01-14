static const char gVertexShader[] = 
    "attribute vec4 vPosition;\n"
	"uniform mat4 Projection;\n"
	"uniform mat4 Model;\n"
    "void main() {\n"
    "  gl_Position = Projection * Model * vPosition;\n"
    "}\n";

//@note: for android, uncomment first line!
static const char gFragmentShader[] =
	//"precision mediump float;\n"
    "uniform vec3 fragColor;\n"
    "void main() {\n"
    "  gl_FragColor = vec4(fragColor, 1.0);\n"
    "}\n";




static const char gVertexTexturedShader[] =
	"attribute vec4 vPosition;\n"
	"uniform mat4 Projection;\n"
	"uniform mat4 Model;\n"
	"attribute vec2 texture_coord;\n"
	"varying vec2 texture_coord_from_vshader;\n"
	"void main() {\n"
	"	gl_Position = Projection * Model * vPosition;\n"
	"	texture_coord_from_vshader = texture_coord;\n"
	"}\n";





//@note: for android, uncomment first line!
static const char gFragmentTexturedShader[] =
	//"precision mediump float;\n"
	"varying vec2 texture_coord_from_vshader;\n"
	"uniform vec3 fragColor;\n"
	"uniform sampler2D texture;\n"

	"void main() {\n"




/*	"gl_FragColor.r = texture2D(texture, texture_coord_from_vshader).r;\n"
	"gl_FragColor.g = texture_coord_from_vshader.x;\n"
	"gl_FragColor.b = texture_coord_from_vshader.y;\n"*/

//    "  gl_FragColor = vec4(fragColor, 1.0);\n"
	"gl_FragColor = texture2D(texture, texture_coord_from_vshader);\n"
//	"gl_FragColor.a = 0.3;\n"


	"}\n";