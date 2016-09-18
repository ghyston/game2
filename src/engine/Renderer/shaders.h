static const char gVertexShader[] =
	"uniform mat4 Model;\n"
	"uniform mat4 Projection;\n"
    "attribute vec4 vPosition;\n"
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
	"uniform sampler2D texture1;\n"
	"uniform sampler2D texture2;\n"

	"void main() {\n"

	"vec4 tex1Clr = texture2D(texture1, texture_coord_from_vshader);\n"

	"vec4 tex2Clr = texture2D(texture2, texture_coord_from_vshader);\n"

	/*"if(tex1Clr.a > 0.0)\n"
	"gl_FragColor = tex2Clr;\n"
	"else\n"
	"gl_FragColor = vec4(fragColor, 0.5);\n"*/

/*	"gl_FragColor.r = texture2D(texture, texture_coord_from_vshader).r;\n"
	"gl_FragColor.g = texture_coord_from_vshader.x;\n"
	"gl_FragColor.b = texture_coord_from_vshader.y;\n"*/

    //"  gl_FragColor = vec4(fragColor, 1.0);\n"
	"gl_FragColor = texture2D(texture1, texture_coord_from_vshader);\n"
//	"gl_FragColor.a = 0.3;\n"


	"}\n";

static const char gVertexBWShader[] =
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
static const char gFragmentBWShader[] =
//"precision mediump float;\n"
"varying vec2 texture_coord_from_vshader;\n"
"uniform vec3 fragColor;\n"
"uniform sampler2D texture;\n"

"void main() {\n"

"vec4 texClr = texture2D(texture, texture_coord_from_vshader);\n"
"float avgClr = (texClr.r + texClr.g + texClr.b) / 3.0;\n"
"float lumClr = 0.21 * texClr.r + 0.72 * texClr.g + 0.07 * texClr.b;\n"
"gl_FragColor = vec4(lumClr, lumClr, lumClr, 1.0);\n"

"}\n";

static const char gVertexBlurShader[] =
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
static const char gFragmentBlurShader[] =
//"precision mediump float;\n"
"varying vec2 texture_coord_from_vshader;\n"
"uniform vec3 fragColor;\n"
"uniform sampler2D texture;\n"

"void main() {\n"

"vec4 res = vec4(0.0);;\n"
"float count = 0.0;\n"
"float tshold = 0.01;\n"

"for (float i=-tshold; i<tshold; i+=tshold/10.0)\n"
"{\n"
"	float coeff = (tshold - abs(i))/tshold;\n"
"	res += coeff * texture2D(texture, texture_coord_from_vshader + vec2(i, 0)) + "
"			coeff * texture2D(texture, texture_coord_from_vshader + vec2(0, i));"
" count += coeff * 2.0;\n"
"}"
"res.r = res.r / count;\n"
"res.g = res.g / count;\n"
"res.b = res.b / count;\n"
"res.a = 1.0;\n"
"gl_FragColor = res;\n"

"}\n";















