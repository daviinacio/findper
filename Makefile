ifeq ($(OS),Windows_NT)
	CFLAGS+=-static-libgcc -static-libstdc++
	CFILE=findper.exe
	IFOLDER="%appdata%\daviinacio"

	CINSTALL=if not exist $(IFOLDER) (mkdir $(IFOLDER) && echo $(INSTALLED_MSG)) ELSE (echo $(INSTALLED_MSG)) & copy $(CFILE) $(IFOLDER) && set PATH=%PATH%;%APPDATA%\daviinacio
	CUNINSTALL=del $(IFOLDER)\$(CFILE)

else
	UNAME_O := $(shell uname -o)
	
	ifeq ($(UNAME_O),GNU/Linux)
        CFILE=findper
		IFOLDER=/usr/local/bin

		CINSTALL=sudo install $(CFILE) $(IFOLDER) && echo $(INSTALLED_MSG)
		CUNINSTALL=sudo rm $(IFOLDER)/$(CFILE)

	endif
	ifeq ($(UNAME_O),Android)
		CFILE=findper
		IFOLDER=/data/data/com.termux/files/usr/bin

		CINSTALL=install $(CFILE) $(IFOLDER) && echo $(INSTALLED_MSG)
		CUNINSTALL=rm $(IFOLDER)/$(CFILE)
    endif

endif

INSTALLED_MSG=Installed on $(IFOLDER)


findper: main.cpp
	@g++ main.cpp -o $(CFILE) -I. $(CFLAGS)

install: findper
	@$(CINSTALL)

uninstall:
	@$(CUNINSTALL)

