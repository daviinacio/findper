ifeq ($(OS),Windows_NT)
	CFILE=findper.exe
	IFOLDER=C:/windows/system32
	ICMD=cp
else
	CFILE=findper
	IFOLDER=~/../usr/bin
	ICMD=install
endif


findper: main.cpp
	@g++ main.cpp -o $(CFILE) -I.

install: findper
	@$(ICMD) $(CFILE) $(IFOLDER)

