ifeq ($(OS),Windows_NT)
	CFILE=findper.exe
	IFOLDER="%appdata%\daviinacio"

	CINSTALL=copy $(CFILE) $(IFOLDER) && PATH $(IFOLDER)
	CUNINSTALL=del $(IFOLDER)\$(CFILE)

else
	UNAME_O := $(shell uname -o)
	
	ifeq ($(UNAME_O),GNU/Linux)
        CFILE=findper
		IFOLDER=/usr/local/bin

		CINSTALL=sudo install $(CFILE) $(IFOLDER)
		CUNINSTALL=sudo rm $(IFOLDER)/$(CFILE)

	endif
	ifeq ($(UNAME_O),Android)
		CFILE=findper
		IFOLDER=/data/data/com.termux/files/usr/bin

		CINSTALL=install $(CFILE) $(IFOLDER)
		CUNINSTALL=rm $(IFOLDER)/$(CFILE)
    endif

endif


findper: main.cpp
	@g++ main.cpp -o $(CFILE) -I.

install: findper
	@$(CINSTALL)

uninstall:
	@$(CUNINSTALL)

