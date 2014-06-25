# vim: noet ts=4 sw=4 sts=0 fenc=utf8
# Licensed under the MIT License. See COPYING for more details.
# (C) 2014. eXerigumo Clanjor (哆啦比猫/兰威举) <cjxgm@126.com>

CC = g++
LD = g++
CCFLAGS = -std=gnu++14 -march=native -O3 -Wall -march=native
LDFLAGS = 

CCFLAGS += `pkg-config --cflags gtkmm-3.0`
CCFLAGS += `pkg-config --cflags zlib`
LDFLAGS += `pkg-config --libs   gtkmm-3.0`
LDFLAGS += `pkg-config --libs   zlib`

.PHONY: all clean cleanall rebuild reconf test commit install uninstall

all: init app
clean: makefile
	@echo -e "[0;32mcleaning[0m"
	rm -rf build
cleanall: clean
	rm -f makefile
rebuild: clean all
reconf:
	@echo -e "[0;32mreconfiguring[0m"
	./configure
test: all
	@echo -e "[0;32mtesting" "[1;35mphonebook[0m"
	./build/phonebook 
commit: cleanall
	git add .
	git diff --cached
	env LANG=C git commit -a || true
	./configure
install: all
	@echo -e "[0;32minstalling" "[1;35mphonebook[0m"
	install -svm 755 build/phonebook /usr/bin/phonebook
	install -vm 644 res/phonebook.desktop /usr/share/applications/res/phonebook.desktop
uninstall:
	@echo -e "[0;32muninstalling" "[1;35mphonebook[0m"
	rm -f /usr/bin/phonebook
	rm -f /usr/share/applications/res/phonebook.desktop

init: makefile build build/src build/src/nde build/src/nde/action build/src/nde/project build/src/ui
app: makefile build/phonebook
makefile: configure
	@echo -e "[0;32mreconfiguring[0m"
	./configure
build:
	@echo -e "[0;32mmaking" "[1;35mdirectories[0m"
	mkdir -p build
build/src:
	mkdir -p build/src
build/src/nde:
	mkdir -p build/src/nde
build/src/nde/action:
	mkdir -p build/src/nde/action
build/src/nde/project:
	mkdir -p build/src/nde/project
build/src/ui:
	mkdir -p build/src/ui

build/src/nde/project/snapshot.o: src/nde/project/snapshot.cc src/nde/project/snapshot.hh \
 src/nde/project/data.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/main.o: src/main.cc src/ui/gtkmm.hh src/ui/main_window.hh \
 src/ui/contact_input_bar.hh src/ui/info_entry.hh src/ui/contact_list.hh \
 src/ui/contact.hh src/ui/contact_search_bar.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/nde/action/create.o: src/nde/action/create.cc src/nde/action/create.hh \
 src/nde/action/type.hh src/nde/action/../factory.hh \
 src/nde/action/../project/file.hh src/nde/action/../project/data.hh \
 src/nde/action/wrapper.hh src/nde/action/../project/instance.hh \
 src/nde/action/../project/type.hh src/nde/action/../project/../path.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/nde/path.o: src/nde/path.cc src/nde/path.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/nde/action/redo.o: src/nde/action/redo.cc src/nde/action/redo.hh \
 src/nde/action/type.hh src/nde/action/../factory.hh \
 src/nde/action/../project/file.hh src/nde/action/../project/data.hh \
 src/nde/action/wrapper.hh src/nde/action/../project/instance.hh \
 src/nde/action/../project/type.hh src/nde/action/../project/../path.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/ui/contact_search_bar.o: src/ui/contact_search_bar.cc \
 src/ui/contact_search_bar.hh src/ui/gtkmm.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/ui/main_window.o: src/ui/main_window.cc src/ui/main_window.hh \
 src/ui/gtkmm.hh src/ui/contact_input_bar.hh src/ui/info_entry.hh \
 src/ui/contact_list.hh src/ui/contact.hh src/ui/contact_search_bar.hh \
 src/ui/../nde.hh src/ui/../nde/init.hh src/ui/../nde/path.hh \
 src/ui/../nde/factory.hh src/ui/../nde/project.hh \
 src/ui/../nde/project/type.hh src/ui/../nde/project/../action/type.hh \
 src/ui/../nde/project/../action/../project/file.hh \
 src/ui/../nde/project/../action/../project/data.hh \
 src/ui/../nde/project/instance.hh src/ui/../nde/project/snapshot.hh \
 src/ui/../nde/action.hh src/ui/../nde/action/wrapper.hh \
 src/ui/../nde/action/undo.hh src/ui/../nde/action/redo.hh \
 src/ui/../nde/action/create.hh src/ui/../nde/action/remove.hh \
 src/ui/../nde/action/edit.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/nde/project/instance.o: src/nde/project/instance.cc src/nde/project/instance.hh \
 src/nde/project/type.hh src/nde/project/../action/type.hh \
 src/nde/project/../action/../factory.hh \
 src/nde/project/../action/../project/file.hh \
 src/nde/project/../action/../project/data.hh src/nde/project/../path.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/nde/project/file.o: src/nde/project/file.cc src/nde/project/file.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/ui/contact_list.o: src/ui/contact_list.cc src/ui/contact_list.hh \
 src/ui/gtkmm.hh src/ui/contact.hh src/ui/contact_input_bar.hh \
 src/ui/info_entry.hh src/ui/../nde.hh src/ui/../nde/init.hh \
 src/ui/../nde/path.hh src/ui/../nde/factory.hh src/ui/../nde/project.hh \
 src/ui/../nde/project/type.hh src/ui/../nde/project/../action/type.hh \
 src/ui/../nde/project/../action/../project/file.hh \
 src/ui/../nde/project/../action/../project/data.hh \
 src/ui/../nde/project/instance.hh src/ui/../nde/project/snapshot.hh \
 src/ui/../nde/action.hh src/ui/../nde/action/wrapper.hh \
 src/ui/../nde/action/undo.hh src/ui/../nde/action/redo.hh \
 src/ui/../nde/action/create.hh src/ui/../nde/action/remove.hh \
 src/ui/../nde/action/edit.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/nde/action/type.o: src/nde/action/type.cc src/nde/action/type.hh \
 src/nde/action/../factory.hh src/nde/action/../project/file.hh \
 src/nde/action/../project/data.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/nde/action/undo.o: src/nde/action/undo.cc src/nde/action/undo.hh \
 src/nde/action/type.hh src/nde/action/../factory.hh \
 src/nde/action/../project/file.hh src/nde/action/../project/data.hh \
 src/nde/action/wrapper.hh src/nde/action/../project/instance.hh \
 src/nde/action/../project/type.hh src/nde/action/../project/../path.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/nde/action/remove.o: src/nde/action/remove.cc src/nde/action/remove.hh \
 src/nde/action/type.hh src/nde/action/../factory.hh \
 src/nde/action/../project/file.hh src/nde/action/../project/data.hh \
 src/nde/action/wrapper.hh src/nde/action/../project/instance.hh \
 src/nde/action/../project/type.hh src/nde/action/../project/../path.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/ui/contact_input_bar.o: src/ui/contact_input_bar.cc \
 src/ui/contact_input_bar.hh src/ui/gtkmm.hh src/ui/info_entry.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/nde/project/type.o: src/nde/project/type.cc src/nde/project/type.hh \
 src/nde/project/../action/type.hh \
 src/nde/project/../action/../factory.hh \
 src/nde/project/../action/../project/file.hh \
 src/nde/project/../action/../project/data.hh src/nde/project/../path.hh \
 src/nde/project/snapshot.hh src/nde/project/../action/helper.hh \
 src/nde/project/../action/../project/instance.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/ui/contact.o: src/ui/contact.cc src/ui/contact.hh src/ui/gtkmm.hh \
 src/ui/contact_input_bar.hh src/ui/info_entry.hh src/ui/../nde.hh \
 src/ui/../nde/init.hh src/ui/../nde/path.hh src/ui/../nde/factory.hh \
 src/ui/../nde/project.hh src/ui/../nde/project/type.hh \
 src/ui/../nde/project/../action/type.hh \
 src/ui/../nde/project/../action/../project/file.hh \
 src/ui/../nde/project/../action/../project/data.hh \
 src/ui/../nde/project/instance.hh src/ui/../nde/project/snapshot.hh \
 src/ui/../nde/action.hh src/ui/../nde/action/wrapper.hh \
 src/ui/../nde/action/undo.hh src/ui/../nde/action/redo.hh \
 src/ui/../nde/action/create.hh src/ui/../nde/action/remove.hh \
 src/ui/../nde/action/edit.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/nde/action/edit.o: src/nde/action/edit.cc src/nde/action/edit.hh \
 src/nde/action/type.hh src/nde/action/../factory.hh \
 src/nde/action/../project/file.hh src/nde/action/../project/data.hh \
 src/nde/action/wrapper.hh src/nde/action/../project/instance.hh \
 src/nde/action/../project/type.hh src/nde/action/../project/../path.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/nde/init.o: src/nde/init.cc src/nde/project/instance.hh \
 src/nde/project/type.hh src/nde/project/../action/type.hh \
 src/nde/project/../action/../factory.hh \
 src/nde/project/../action/../project/file.hh \
 src/nde/project/../action/../project/data.hh src/nde/project/../path.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/src/ui/info_entry.o: src/ui/info_entry.cc src/ui/info_entry.hh src/ui/gtkmm.hh makefile
	@echo -e "[0;32mcompiling" "[1;35m$@[0m"
	$(CC) -c -o $@ $< $(CCFLAGS)
build/phonebook: build/src/nde/project/snapshot.o build/src/main.o build/src/nde/action/create.o build/src/nde/path.o build/src/nde/action/redo.o build/src/ui/contact_search_bar.o build/src/ui/main_window.o build/src/nde/project/instance.o build/src/nde/project/file.o build/src/ui/contact_list.o build/src/nde/action/type.o build/src/nde/action/undo.o build/src/nde/action/remove.o build/src/ui/contact_input_bar.o build/src/nde/project/type.o build/src/ui/contact.o build/src/nde/action/edit.o build/src/nde/init.o build/src/ui/info_entry.o
	@echo -e "[0;32mlinking" "[1;35m$@[0m"
	$(LD) -o $@ $^ $(LDFLAGS)

