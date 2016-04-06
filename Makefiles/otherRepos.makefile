GTEST_FOLDER = Repos/gtest/googletest
GTEST_LIBRARY = Repos/gtest/googletest/libgtest.a
GTEST_HEADER = Repos/gtest/googletest/include

GMOCK_FOLDER = Repos/gtest/googlemock
GMOCK_LIBRARY = Repos/gtest/googlemock/libgmock.a
GMOCK_HEADER = Repos/gtest/googlemock/include

$(GTEST_FOLDER):
	git clone git@github.com:google/googletest.git Repos/gtest

$(GTEST_LIBRARY): $(GTEST_HEADER)
	cd Repos/gtest/googletest/ ; \
	cmake . ; \
	make ;

$(GTEST_HEADER): $(GTEST_FOLDER)

$(GMOCK_FOLDER):
	git clone git@github.com:google/googletest.git Repos/gtest

$(GMOCK_LIBRARY): $(GMOCK_HEADER)
	cd Repos/gtest/googlemock/ ; \
	cmake . ; \
	make ;

$(GMOCK_HEADER): $(GMOCK_FOLDER)
