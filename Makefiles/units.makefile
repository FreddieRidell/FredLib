Src/%.o: Src/%.cpp
	@ echo "Compling Source: $<"
	@ $(CC) -c $< \
	$(INCLUDEPATHS) \
	$(COMPILEFLAGS) \
	-o $@ 

Test/%.o: Test/%.cpp $(GTEST_HEADER) $(GMOCK_HEADER)
	@ echo "Compiling Test: $<"
	@ $(CC) -c $< \
	$(INCLUDEPATHS) \
	-I$(GTEST_HEADER) \
	-I$(GMOCK_HEADER) \
	$(COMPILEFLAGS) \
	-o $@ 

%.d: %.cpp $(GTEST_HEADER) $(GMOCK_HEADER)
	@ echo "Generating Dependancy File For: $<"
	@ $(CC) -c $< \
	$(INCLUDEPATHS) \
	-I$(GTEST_HEADER) \
	-I$(GMOCK_HEADER) \
	$(COMPILEFLAGS) \
	-MM -MT $(subst .d,.o,$@) \
	-MF $@
