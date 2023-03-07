#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
#include "map.hpp"

#ifndef NS
# define NS ft
#endif
 
 struct PointCmp {
    bool operator()(const int &lhs, const int &rhs) const {
        return lhs > rhs;
    }
};

template<class Key, class Value, class Compare>
void print(const NS::map<Key, Value, Compare> &map) {
	std::cout << "size = " << map.size() << std::endl;
	for(typename NS::map<Key, Value, Compare>::const_iterator p = map.begin(); p != map.end(); ++ p)
			std::cout << (*p).first << ", is " << (*p).second << std::endl;
	std::cout << std::endl;
};

void init_array_int_str(NS::pair<int, std::string>* arr, std::size_t size)
{
    std::string x[64] = { "CBCId4lUU6oYms60JkNr", "V5sbXjlqYRAV1C1LgJbt", "TPcK94z2htaoK5hWpR1j",
                          "WA1JMsjadjyjQjJLxVkE", "aDhJUsH7AVnKLfzQGcPC", "DPpRIm6G9C5CWSWYLwnt",
                          "aKyxvwuxzUAksmm7s8o3", "d8NpBFRFI87WxlYiRzJB", "5RDlRrY8OFBkqtlD5R33",
                          "W4dsiGdNWranxT1qbPt9", "uUxBDNzk3Tpg1bIow0uf", "FiKAXgTFhhPhmRkfXci9",
                          "02Fxrj1KnMufOpH1gbxw", "hSV7LrNPzTKHS6h7BRW6", "YzIjmI4i4Fum1gzs9QFy",
                          "6jjGwGu20C7dXFRgdCU8", "bej1zTuyCJGa0b4KXgQO", "ckkK36lt3kBVH1PYvbib",
                          "Gs9kLamEeSWqM9ORSlzF", "oJTGXtRpq4rz6IBt2Gc2", "6XSQM096yPnzWqydO7Fl",
                          "Kw91n77jigS09IQEYFw0", "K0Qj3EOV96U6xbBDMkaP", "i0b4NYygRb7ZuT3HOE61",
                          "C6KyCaoRm5MncGCjjP0I", "6xxl5c88m0Rq5CkTPsTU", "xtZ16NJzNU4IEnzsily8",
                          "2ofwuG2e80JGsK8VdB6r", "UjhRe94EahPlXuBbIV0q", "be5WTfjjKVBU8cezAjH8",
                          "zOWJPAQLV4wgVGJTC0uV", "nuqgXoNhZpL8uMvbDcT7", "HdCk0Gm8Gn3eqcVYxcYD",
                          "PuIS5xPbBpGe3MHG7SNm", "ZY6finqJMbHpB6dKlenn", "VJfBTOFj9reLm3iGU2Fs",
                          "UFWOX8UzTSzSAGMvGRIC", "cZfcw5yVwFprkH2v3FQO", "V34DSjjaiDianUKjRFCj",
                          "j7SHtomH6GvAY8y0nL9E", "3z82NvciqTwWW2Lp7MET", "S1BDCdeUHLIVB6I8zaIc",
                          "OkuQPNHq0AnYY9Pemxpn", "yH5J2tI4oQzVsPBB226z", "aafwp6lvuOxv5JkUBUlA",
                          "RjRwqlQ0hnxYnglid2x3", "3RBzhOIHFtRtZBHNlCVv", "lttYCjRWSXYKeyIgvpJv",
                          "6KhIc7LvaTTwklmmbjBO", "IDlAqFCEdFTJcVW36RsY", "pDGkqtvKVRReq19BFVwN",
                          "88UJAeNtrlAwEu4BGiSb", "eFN5bxsWa4dAnvZdzToE", "B3cqY0IqO2IH2yGMnX7e",
                          "BRcU6oFTAC8IWuiSrTEa", "dtBZVLQMx9MBw1eak8SB", "zM2XVrazn2fXAsRHDc16",
                          "qqlM2sERpGhcZJAv3qPR", "4Lru0dOIQpWGYlcx9oyn", "HSH0O0igQruyLC1FmQVs",
                          "mXHcnXiXhKJwJ0BUSpje", "sXhbSe7MQHhvJ9XQcrrX", "aTejup4iQw70n78erKEB",
                          "1IRLC9sfQI5AzDYeotLd" };

    for (std::size_t i = 0; i < size; ++i) {
        arr[i] = NS::make_pair(rand(), x[i]);
    }
}

void init_array_str_str(NS::pair<std::string, std::string>* arr, std::size_t size)
{
    std::string x[32] = { "RxWAUMME3GtF9Zbv3a4M", "WC96vs7Z6I6TfdGxObUg", "2beuhrfBZvjdkmfqV9yn",
                          "AuIhF3lUgwT0OMy8DuUx", "dVW2KAL06gB4s7rEf508", "jnsp7MGfl5wZNZVfQSvp",
                          "p26Kfhz0Iof6rJDy27vc", "bnWXfp2eexq7MPpcmRSI", "tMEU0L6RNvqDAaV6HN0e",
                          "POcbaPteUMFfltrwdu7r", "epDGhJZoKoL4i1HO67XS", "o83N1RTIeOafqBfqeAYh",
                          "aYRtwuDT8k7k7iIfTrtU", "fEPXIREoFGKXqnNKySG5", "QrqmIbVVIQzf8WKBxiga",
                          "k5NSg0Dq0b9ewfrhYdy7", "Tf9dsqBADfMeWVQGG3Zk", "dS2LouElpUXsXNCClr4B",
                          "tsvf3JaWNg5JlSDZs1Dm", "oWurB8fBAIBQq1ZnlFiR", "8YllXP80XunEXhqnjkZc",
                          "Spt36tVcEkIFjwogWli0", "c25H1u6DF9RVdagn81DA", "AjWfT7TlXgzSKOywpoTH",
                          "ZwTg8WNnmXOJKdW6ZeJv", "E9aYpoCXd1kbSWhdLOnf", "QN1iAuoSNQ5WvHeSeSSL",
                          "7g5wfNllowIaqMUVjywr", "b38gJrosdk9xEQ2K8Gbu", "KdVdRVLHJg9Bazc4cpM7",
                          "COJeGmQEzjXwqKCAnd6J", "2k6XCpXEkP7QoST6uYoy" };

    std::string y[32] = { "TZ3QuE3ZNUbFrEpQhgcY", "BX2lyPzOWRIznb34T5OT", "v7lPrSeDokdBIUXR9QGh",
                          "nAQxkuEYL5k1Er7FspKu", "r8T4oZaWBI1m7sPBEDz3", "pdxM9tJrYZskZla7L7yM",
                          "dIIx6eKTfygu24SNKa32", "tw04BOo705mdWxuDciNO", "q94icFprhKrrFXLvjEN3",
                          "uM25BWUl14NTlTwFsNIv", "2oTV9fXUESLQqzvsPFmd", "W6ASLRzrlOggx5b7CtYN",
                          "bz4BQ7rLU203RNwwmbMK", "jfWgRPiuy1P3NGDPWmbe", "PgtdYLdGuneYEUgMA8SB",
                          "eaaFugCSOOU5my4y4SkG", "gGd4FiUEJwgvhOCSHu9g", "9K0ZhqlbyDCJXYXHoEIN",
                          "VTmk8m7rbEGl8ntGpTCQ", "eRJ98PUF2tSMX6zpDOi4", "wFMJIDAbjYnJkxMxkAtL",
                          "JCOXV4iPcIt72DcNnbuY", "LsnOUrHHD2FNFH5DMvbc", "YVPp2jPqK3jmif7yY14r",
                          "JBMhRRtLY3QX3x1ZVDCs", "Uwo5PD2RLMx5ByW9Rscq", "O4Q6DPBJHOelMtBKc9GQ",
                          "Bq0H2eqnuCYqyj9F5Lkn", "P2fJf0TYN92iUXkwELjG", "f656ltXlumpc7YyPVjan",
                          "YQfr76LAA1xKokfq8HpL", "6utvLeZ9t0IM4OkdfAQ2" };

    for (std::size_t i = 0; i < size; ++i) {
        arr[i] = NS::make_pair(x[i], y[i]);
    }
}

void PRINT_LINE(std::string msg, int value)
{
    std::cout << msg << " " << (value) << std::endl;                                                        
}


void PRINT_PAIR_REF( NS::pair<int, std::string> p) {
	std::cout << "Key:" << p.first << "Value:" << p.second << std::endl;
}

int main() {

    NS::pair<int, std::string> intstr_arr[64];
    init_array_int_str(intstr_arr, 64);
    NS::pair<std::string, std::string> strstr_arr[32];
    init_array_str_str(strstr_arr, 32);
    // std::size_t intstr_size = 64;
    std::size_t strstr_size = 32;
// 
	typedef NS::map<int, std::string, std::less<int>, std::allocator<NS::pair<const int, std::string> > >
	intmap;
	typedef NS::map<std::string, std::string, std::less<std::string>, std::allocator<NS::pair<const std::string, std::string> > >
    strmap;
	{
	    strmap m(strstr_arr, strstr_arr + strstr_size);

        strmap::iterator it = m.find("ABCD");

        if (it != m.end()) {
            PRINT_PAIR_REF(*it);
        }

        m.insert(NS::make_pair("12345", "etsriueruy394w"));
        m.insert(NS::make_pair("abcd", "sfdge4ta4tqtawefa"));
        m.insert(NS::make_pair("123", "adfgagrawetawtawef"));
        m.insert(NS::make_pair("1234", "asdfgaetfawfasdf"));
        m.insert(NS::make_pair("ab", "adfawtawefgzsdfg"));
        m.insert(NS::make_pair("yz", "gftrjr5y4agwe3ta"));
        m.insert(NS::make_pair("64", "mhj,i;y9o67eysetrgerg"));

        it = m.find("12345");

        if (it != m.end()) {
            PRINT_PAIR_REF(*it);
        }

        it = m.find("1234");

        if (it != m.end()) {
            PRINT_PAIR_REF(*it);
        }

        it = m.find("123");

        if (it != m.end()) {
            PRINT_PAIR_REF(*it);
        }

        it = m.find("123");

        if (it != m.end()) {
            PRINT_PAIR_REF(*it);
        }

        it = m.find("z");

        if (it != m.end()) {
            PRINT_PAIR_REF(*it);
        }

        const strmap cm(m);

        strmap::const_iterator cit = cm.find("ABCD");

        if (cit != cm.end()) {
            PRINT_PAIR_REF(*cit);
        }

        cit = cm.find("64");

        if (cit != cm.end()) {
            PRINT_PAIR_REF(*cit);
        }

        cit = m.find("12345");

        if (cit != m.end()) {
            PRINT_PAIR_REF(*cit);
        }

        cit = m.find("1234");

        if (cit != m.end()) {
            PRINT_PAIR_REF(*cit);
        }

        cit = m.find("123");

        if (cit != m.end()) {
            PRINT_PAIR_REF(*cit);
        }

        cit = m.find("123");

        if (cit != m.end()) {
            PRINT_PAIR_REF(*cit);
        }

        cit = m.find("z");

        if (cit != m.end()) {
            PRINT_PAIR_REF(*cit);
        }
    }

    // {
    //     const intmap cm;

    //     if (cm.find(0) != cm.end()) {
    //         PRINT_PAIR_PTR(cm.find(0));
    //     }

    //     intmap m;

    //     m.insert(NAMESPACE::make_pair(123, "Hello"));

    //     if (m.find(0) != m.end()) {
    //         PRINT_PAIR_PTR(m.find(0));
    //     }
    //     if (m.find(123) != m.end()) {
    //         PRINT_PAIR_PTR(m.find(123));
    //     }
    // }

/*
// ################################  CONSTRUCTORS  ##############
	std::cout << "\e[7m=============CONSTRUCTORS============\e[0m" << std::endl;
	{
		// (1) Default constructor
		NS::map<std::string, int> map1;
		map1["1"] = 69;
		map1["2"] = 199;
		map1["3"] = 50;
		print(map1);
		
		// (4) Range constructor
		NS::map<std::string, int> iter(map1.find("anything"), map1.end());
		std::cout << "iter = " << std::endl;
		print(iter);
		std::cout << "map1 = " << std::endl;
		print(map1);
		
		// (6) Copy constructor
		NS::map<std::string, int> copied(map1);
		std::cout << "copied = " << std::endl;
		print(copied);
		std::cout << "map1 = " << std::endl;
		print(map1);
		
		// Use a comparison struct
		NS::map<int, double, PointCmp> mag;
		mag[5] = 13;
		mag[4] = 5;
		mag[15] = 17;	
		print(mag);
	}
	std::cout << std::endl;

// ################################  ELEMENT ACCESS  ##############
	std::cout << "\e[7m=============ELEMENT ACCESS============\e[0m" << std::endl;
	{
		NS::map<std::string,int> mymap;
        mymap["alpha"] = 0;
        mymap["beta"] = 0;
        mymap["gamma"] = 0;
		print(mymap);

  		mymap.at("alpha") = 10;
  		mymap.at("beta") = 20;
  		mymap.at("gamma") = 30;
		// std::cout << mymap.at("test") << std::endl;
		
		print(mymap);
	}
// ################################  MODIFIERS  ##############
	std::cout << "\e[7m=============MODIFIERS============\e[0m" << std::endl;
	{
		std::cout << "\e[7m Insert \e[0m" << std::endl;
		NS::map<char,int> mymap;
		// first insert function version (single parameter):
		mymap.insert ( NS::pair<const char,int>('a',100) );
		mymap.insert ( NS::pair<const char,int>('z',200) );

		NS::pair<NS::map<const char,int>::iterator,bool> ret;
		ret = mymap.insert ( NS::pair<const char,int>('z',500) );
		if (ret.second==false) {
			std::cout << "element 'z' already existed";
			std::cout << " with a value of " << ret.first->second << std::endl;
		}

		// // second insert function version (with hint position):
		// NS::map<const char,int>::iterator it = mymap.begin();
		// mymap.insert (it, NS::pair<const char,int>('b',300));  // max efficiency inserting
		// mymap.insert (it, NS::pair<const char,int>('c',400));  // no max efficiency insertiNS
		
		// third insert function version (range insertion):
		NS::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));

		// showing contents:
		std::cout << "mymap contains:" << std::endl; 
		print(mymap);
		std::cout << "anothermap contains:" << std::endl;
		print(anothermap);
	}
	{
		std::cout << "\e[7m Erase \e[0m" << std::endl;
		NS::map<char,int> mymap;
		NS::map<char,int>::iterator it;
		// insert some values:
		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;
		mymap['d']=40;
		mymap['e']=50;
		mymap['f']=60;
		std::cout << "mymap contains:" << std::endl;
		print(mymap);
		it=mymap.find('b');
		mymap.erase (it);                   // erasing by iterator
		mymap.erase ('c'); 					// erasing by key
		std::cout << "mymap contains:" << std::endl;
		print(mymap);                 
		it=mymap.find ('e');
		mymap.erase ( it, mymap.end() );    // erasing by range
		std::cout << "mymap contains:" << std::endl;
		print(mymap);
	}
	{
		std::cout << "\e[7m Swap \e[0m" << std::endl;
		NS::map<char,int> foo,bar;
		foo['x']=100;
		foo['y']=200;
		bar['a']=11;
		bar['b']=22;
		bar['c']=33;
		foo.swap(bar);
		std::cout << "foo contains:" << std::endl;
		print(foo);
		std::cout << "bar contains:" << std::endl;
		print(bar);
	}
	{
		std::cout << "\e[7m Clear \e[0m" << std::endl;
		NS::map<char,int> mymap;
		mymap['x']=100;
		mymap['y']=200;
		mymap['z']=300;
		std::cout << "mymap contains:" << std::endl;
		print(mymap);
		mymap.clear();
		std::cout << "mymap contains:" << std::endl;
		print(mymap);
		mymap['a']=1101;
		mymap['b']=2202;
		std::cout << "mymap contains:" << std::endl;
		print(mymap);
	}
// ################################  OPERATIONS  ##############
	std::cout << "\e[7m=============OPERATIONS============\e[0m" << std::endl;
	{
		std::cout << "\e[7m Find \e[0m" << std::endl;
		NS::map<char,int> mymap;
		NS::map<char,int>::iterator it;

		mymap['a']=50;
		mymap['b']=100;
		mymap['c']=150;
		mymap['d']=200;

		it = mymap.find('b');
		if (it != mymap.end())
			mymap.erase (it);

		// print content:
		std::cout << "elements in mymap:" << std::endl;
		std::cout << "a => " << mymap.find('a')->second << std::endl;
		std::cout << "c => " << mymap.find('c')->second << std::endl;
		std::cout << "d => " << mymap.find('d')->second << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "\e[7m Count \e[0m" << std::endl;
		NS::map<char,int> mymap;
		char c;
		mymap ['a']=101;
		mymap ['c']=202;
		mymap ['f']=303;
		for (c='a'; c<'h'; c++)
		{
			std::cout << c;
			if (mymap.count(c)>0)
			std::cout << " is an element of mymap." << std::endl;
			else 
			std::cout << " is not an element of mymap." << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << "\e[7m Lower/Upper_bound \e[0m" << std::endl;
		NS::map<char,int> mymap;
		NS::map<char,int>::iterator itlow,itup;

		mymap['a']=20;
		mymap['b']=40;
		mymap['c']=60;
		mymap['d']=80;
		mymap['e']=100;

		itlow=mymap.lower_bound ('b');  // itlow points to b
		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

		mymap.erase(itlow,itup);        // erases [itlow,itup)
		print(mymap);
	}

	// std::cout << "empty: " << map_int.empty() << std::endl;
	// std::cout << "max size: " << map_int.max_size() << std::endl;
	*/
}