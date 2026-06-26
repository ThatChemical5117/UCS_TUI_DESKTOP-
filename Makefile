# ==== Workspace Global Make file ====
# Put this make file in the root directory of your project

# configuration default
ifndef config
	config = debug
endif

#Add All project names, Project name should be the same as the Directory it is in
# keep adding additional project names after 
PROJECTS := Application 
.PHONY: all clean $(PROJECTS) uninstall install 

all: $(PROJECTS)

Application: 
	@echo "==== Building ($@) ($(config)) ===="
	@$(MAKE) --no-print-directory -C $@ -f Makefile config=$(config)

#add Extra rules with the same format, Use name of directory that project is in 

install: all
	@$(MAKE) --no-print-directory -C Application -f Makefile install config=$(config)

uninstall:
	@$(MAKE) --no-print-directory -C Application -f Makefile uninstall 

# add a line for each project, use Directory name
clean:
	@${MAKE} --no-print-directory -C Application -f Makefile clean
