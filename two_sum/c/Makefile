build:
	cl /c submit2.c
	lib submit2.obj

test: build
	cl submit2.lib test.c
	test.exe

clean:
	@if exist *obj del *obj
	@if exist *lib del *lib
	@if exist *exe del *exe
