Src/%.o: Src/%.cpp
	@ echo "Compling Source: $<"
	@ $(CC) -c $< \
	$(INCLUDEPATHS) \
	$(COMPILEFLAGS) \
	-o $@ 

Test/%.o: Test/%.cpp 
	@ echo "Compiling Test: $<"
	@ $(CC) -c $< \
	$(INCLUDEPATHS) \
	$(TEST_INCLUDE_PATHS) \
	$(COMPILEFLAGS) \
	-o $@ 

%.d: %.cpp 
	@ echo "Generating Dependancy File For: $<"
	@ $(CC) -c $< \
	$(INCLUDEPATHS) \
	$(TEST_INCLUDE_PATHS) \
	$(COMPILEFLAGS) \
	-MM -MT $(subst .d,.o,$@) \
	-MF $@
