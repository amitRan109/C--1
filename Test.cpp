#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;


TEST_CASE("Test replacement of v and w") { //8
    string text = "www worry yyy windows";
    CHECK(find(text, "worry") == string("worry"));
    CHECK(find(text, "vorry") == string("worry"));

    CHECK(find(text, "www") == string("www"));
    CHECK(find(text, "wvw") == string("www"));
    CHECK(find(text, "vvv") == string("www"));

    CHECK(find(text, "windows") == string("windows"));
    CHECK(find(text, "vindows") == string("windows"));
    CHECK(find(text, "vindovs") == string("windows"));

}

TEST_CASE("Test replacement of b and p") { //8
    string text = "be xxx happy yyy bubble";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));

    CHECK(find(text, "pe") == string("be"));

    CHECK(find(text, "bupple") == string("bubble"));
    CHECK(find(text, "bubple") == string("bubble"));
    CHECK(find(text, "pupple") == string("bubble"));
}


TEST_CASE("Test replacement of b and f") { //8
    string text = "xxx happy bbb ";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "habfy") == string("happy"));
    CHECK(find(text, "hafby") == string("happy"));

    CHECK(find(text, "bbb") == string("bbb"));
    CHECK(find(text, "fff") == string("bbb"));
    CHECK(find(text, "bfb") == string("bbb"));
    CHECK(find(text, "ffb") == string("bbb"));

}

TEST_CASE("Test replacement of g and j") { //8
    string text = "xxx google jungle";
    CHECK(find(text, "google") == string("google"));
    CHECK(find(text, "joogle") == string("google"));
    CHECK(find(text, "joojle") == string("google"));
    CHECK(find(text, "goojle") == string("google"));

    CHECK(find(text, "jungle") == string("jungle"));
    CHECK(find(text, "gungle") == string("jungle"));
    CHECK(find(text, "junjle") == string("jungle"));
    CHECK(find(text, "gunjle") == string("jungle"));

}

TEST_CASE("Test replacement of c and k") { //8
    string text = "xxx cookie yyy kahoot city";
    CHECK(find(text, "cookie") == string("cookie"));
    CHECK(find(text, "kookie") == string("cookie"));
    CHECK(find(text, "coocie") == string("cookie"));
    CHECK(find(text, "koocie") == string("cookie"));

    CHECK(find(text, "kahoot") == string("kahoot"));
    CHECK(find(text, "cahoot") == string("kahoot"));

    CHECK(find(text, "city") == string("city"));
    CHECK(find(text, "kity") == string("city"));
}

TEST_CASE("Test replacement of c and q") { //4
    string text = "xxx quick  yyy";
    CHECK(find(text, "cuick") == string("quick"));
    CHECK(find(text, "quiqk") == string("quick"));
    CHECK(find(text, "quick") == string("quick"));
    CHECK(find(text, "cuiqk") == string("quick"));
}

TEST_CASE("Test replacement of k and q") { //4
    string text = "king quality";
    CHECK(find(text, "king") == string("king"));
    CHECK(find(text, "qing") == string("king"));

    CHECK(find(text, "kuality") == string("quality"));
    CHECK(find(text, "quality") == string("quality"));
    
}

TEST_CASE("Test replacement of s and z") { //10
    string text = "buzz sucsses";
    CHECK(find(text, "buzz") == string("buzz"));
    CHECK(find(text, "busz") == string("buzz"));
    CHECK(find(text, "buss") == string("buzz"));
    CHECK(find(text, "buzs") == string("buzz"));
    
    CHECK(find(text, "sucsses") == string("sucsses"));
    CHECK(find(text, "zucsses") == string("sucsses"));
    CHECK(find(text, "suczzes") == string("sucsses"));
    CHECK(find(text, "suczsez") == string("sucsses"));
    CHECK(find(text, "zuczzez") == string("sucsses"));
    CHECK(find(text, "suczzez") == string("sucsses"));


}

TEST_CASE("Test replacement of d and t") {
     string text = "Dont Told";
    CHECK(find(text, "Dont") == string("Dont"));
    CHECK(find(text, "Dond") == string("Dont"));
    CHECK(find(text, "tont") == string("Dont"));
    CHECK(find(text, "tond") == string("Dont"));
    
    CHECK(find(text, "Told") == string("Told"));
    CHECK(find(text, "tolt") == string("Told"));
    CHECK(find(text, "dold") == string("Told"));
    CHECK(find(text, "dolt") == string("Told"));
    CHECK(find(text, "DolD") == string("Told"));
    CHECK(find(text, "TolT") == string("Told"));

}

TEST_CASE("Test replacement of o and u") {
     string text = "You xxx out";
    CHECK(find(text, "You") == string("You"));
    CHECK(find(text, "YUO") == string("You"));
    CHECK(find(text, "Yuu") == string("You"));
    CHECK(find(text, "Yoo") == string("You"));
    
    CHECK(find(text, "out") == string("out"));
    CHECK(find(text, "uot") == string("out"));
    CHECK(find(text, "oot") == string("out"));
    CHECK(find(text, "uut") == string("out"));
   
}

TEST_CASE("Test replacement of i and y") {
      string text = "ivgeny yyy lili";
    CHECK(find(text, "ivgeny") == string("ivgeny"));
    CHECK(find(text, "yvgeny") == string("ivgeny"));
    CHECK(find(text, "ivgeni") == string("ivgeny"));
    CHECK(find(text, "yvgeni") == string("ivgeny"));
    
    CHECK(find(text, "lili") == string("lili"));
    CHECK(find(text, "lyli") == string("lili"));
    CHECK(find(text, "lyly") == string("lili"));
    CHECK(find(text, "lily") == string("lili"));
}



TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    
}
TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "xxx yyy Worry";
    CHECK(find(text, "worry") == string("Worry"));
    CHECK(find(text, "Worry") == string("Worry"));
    CHECK(find(text, "WORRY") == string("Worry"));
    CHECK(find(text, "WoRrY") == string("Worry"));
}

TEST_CASE("Test many replacement in one word") {
    string text = "Luka doncic";
    CHECK(find(text, "Luka") == string("Luka "));
    CHECK(find(text, "loca") == string("Luka "));
    CHECK(find(text, "Luqa") == string("Luka "));
    CHECK(find(text, "loQa") == string("Luka ")); 

    CHECK(find(text, "doncic") == string("doncic "));
    CHECK(find(text, "tunkyq") == string("doncic "));
    CHECK(find(text, "Donkyk") == string("doncic "));
    CHECK(find(text, "TunQik") == string("doncic "));
    CHECK(find(text, "tuncic") == string("doncic "));
    CHECK(find(text, "tuncyc") == string("doncic "));
    
}

