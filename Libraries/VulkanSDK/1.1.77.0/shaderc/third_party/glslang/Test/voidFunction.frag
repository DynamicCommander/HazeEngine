#version 120

uniform vec4 bigColor;
varying vec4 BaseColor;
uniform float d;

float bar = 2.0;

void foo()
{
    bar++;

	return;
}

void foo2()
{
    bar++;
}

void main()
{
	vec4 outColor = bigColor;

	foo();

	foo2();

	outColor.x += bar;

    gl_FragColor = outColor;

	return;
}
