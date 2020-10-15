#include <gtest/gtest.h>
#include <fstream>
#include <istream>
#include "../Json_parser.cpp"

TEST(parserTest, test_filename){
	std::string filename;
	std::map<std::string, std::string> testOutput; 
	std::map<std::string, std::string> expectedOutput;
	expectedOutput={
		{"name", "Fanni"},
		{"hp", "30000"},
		{"dmg", "500"}};
	filename="../Units/Unit1.json";                       
	testOutput = Json_parser::Parse(filename);
	for (auto iter : expectedOutput){
		ASSERT_EQ(testOutput[iter.first],expectedOutput[iter.first]);
	}
}

TEST(parserTest, test_filecontent){
	std::string filecontent;
	std::map<std::string, std::string> testOutput; 
	std::map<std::string, std::string> expectedOutput;
	expectedOutput={
		{"name", "Fanni"},
		{"hp", "30000"},
		{"dmg", "500"}};
	filecontent="{\"name\" : \"Fanni\",\n\"hp\" : 30000,\n\"dmg\" : 500\n}";            
	testOutput = Json_parser::ParseContent(filecontent);
	for (auto iter : expectedOutput){
		ASSERT_EQ(testOutput[iter.first],expectedOutput[iter.first]);
	}
}


TEST(parserTest, test_stream){
	std::map<std::string, std::string> testOutput; 
	std::map<std::string, std::string> expectedOutput;
	expectedOutput={
		{"name", "Fanni"},
		{"hp", "30000"},
		{"dmg", "500"}};
 	std::filebuf fb;
 	if (fb.open ("Units/Unit1.json",std::ios::in)){
		std::istream is(&fb);
		fb.close();
		testOutput=Json_parser::Parse(is);
		for (auto iter : expectedOutput){
			ASSERT_EQ(testOutput[iter.first],expectedOutput[iter.first]);
		}		
	}
}
			 
int main(int argc, char** argv ){
	::testing::InitGoogleTest (&argc, argv);
	return RUN_ALL_TESTS();
}