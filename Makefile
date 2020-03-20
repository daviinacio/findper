ifeq ($(OS),Windows_NT)
	CFILE=findper.exe
	IFOLDER="%appdata%\daviinacio"

	CINSTALL=copy $(CFILE) $(IFOLDER) && PATH $(IFOLDER)
	CUNINSTALL=del $(IFOLDER)\$(CFILE)

else
	UNAME_S := $(shell uname -s)
	
	ifeq ($(UNAME_S),Linux)
        CFILE=findper
		IFOLDER=/usr/local/bin

		CINSTALL=sudo install $(CFILE) $(IFOLDER)
		CUNINSTALL=sudo rm $(IFOLDER)/$(CFILE)

	else
		CFILE=findper
		IFOLDER=/data/data/com.termux/files/usr/bin

		CINSTALL=sudo install $(CFILE) $(IFOLDER)
		CUNINSTALL=sudo rm $(IFOLDER)/$(CFILE)
    endif

endif


findper: main.cpp
	@g++ main.cpp -o $(CFILE) -I.

install: findper
	@$(CINSTALL)

uninstall:
	@$(CUNINSTALL)

