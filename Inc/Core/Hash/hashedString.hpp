#pragma once

namespace core {
namespace hash {


//class HashedString{
//private:
    //std::string str;
    //unsigned long stringHash;

//public:
    //HashedString();
    //HashedString(const std::string& string);
    //HashedString(const HashedString& hashedString);
    //HashedString(const char* cString);

    //HashedString& operator = (const HashedString&);
    //HashedString& operator = (const std::string&);
    //HashedString& operator = (const char*);

    //inline const unsigned long getHash() const{
        //return stringHash;
    //}

    //inline const std::string& getString() const{
        //return str;
    //}

    //inline const char* c_str() const{
        //return str.c_str();
    //}

    //inline const HashedString operator + (const char* appnd) const {
        //std::string generatorString = str + appnd;
        //HashedString returnHS(generatorString);
        //return returnHS;
    //}
    //inline const HashedString operator + (const std::string appnd) const {
        //std::string generatorString = str + appnd;
        //HashedString returnHS(generatorString);
        //return returnHS;
    //}
    //inline const HashedString operator + (const HashedString appnd) const {
        //std::string generatorString = str + appnd.str;
        //HashedString returnHS(generatorString);
        //return returnHS;
    //}

    //inline const bool operator == (const HashedString& rhs) const { return getHash() == rhs.getHash(); }
    //inline const bool operator != (const HashedString& rhs) const { return !operator==(rhs); }
    //inline const bool operator == (const std::string& rhs)  const { return getHash() == hash(rhs); }
    //inline const bool operator != (const std::string& rhs)  const { return !operator==(rhs); }
    //inline const bool operator == (const char* rhs)         const { return getHash() == hash(rhs); }
    //inline const bool operator != (const char* rhs)         const { return !operator==(rhs); }
    //inline const bool operator == (const unsigned long rhs) const { return getHash() == rhs; }
    //inline const bool operator != (const unsigned long rhs) const { return !operator==(rhs); }
//};

//}

//std::ostream& operator<<(std::ostream& os, const crypto::HashedString& hs);

} //hash
} //core
