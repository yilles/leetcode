build:
	cl /c submit1.c
	lib submit1.obj

test: build
	cl submit1.lib test.c
	test.exe

clean:
	@if exist *obj del *obj
	@if exist *lib del *lib
	@if exist *exe del *exe
