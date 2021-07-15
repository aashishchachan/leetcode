#include <bits/stdc++.h>
using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define external_io() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define secsort() bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){return (a.second < b.second);}
#define MOD 1000000007
#define MAXN 100005


void data_types(){
    // const, static etc. 
    // sizes of different data types
}

void arrays(){
    // 2d arrays, dynamic arrays, const char*, char** const lauda lassan
    // int n;
    // int arr[n];         // garbage value
    // int arr[n] = {0};   // initialise all elements with zero
    // int arr[n] = {-2};  // not valid, can only be initialised with zero.
}

void strings(){
    // taking string input with spaces
    string i;
    getline(cin, i);
    cout << i<<endl;

    //string concatenations (+=, append), assume time complexity to be linear
    string str1 = "hello there", str2 = "how are";
    str1 += str2;               // both are same
    str1.append(str2);          // both are same

    //to concatenate part of a string:
    str1.append(str2, 4, 2);    // (string, starting index, number of chars to add)
    cout << str1 << endl;

    // strings comparison
    str1.compare(str2);         // returns 0 if equal, >0 if str1>str2, <0 if str1<str2 (lexiographically)
                                // don't use strcmp, it takes only const char *    

    // finding substring
    str1.find("hello");         // returns the index to first element of substring in str1

    // fetching substring
    str1.substr(4, 3);          // (starting index, number of chars to fetch)

    // erasing
    str1.erase(4, 3);           // (starting index, number of chars to erase)

    // inserting
    str1.insert(4, "hello");    // (starting index, substr to insert)

    
    // is string[i] is a char?, what if string+=char?
    string str = "hello there!";
    char a = str[2];
    str += a;
    cout << str<< endl;
    //string st = str[1]; //error
    string st = str + str[1];
    cout << st<< endl;
    string stm = str[1] + str;
    cout << stm << endl;
    // result: strings can be treated as a vector of chars and not as a vector of strings.
    // both char and strings can be added to a string to form a string.


    // to convert char to string:
    char b = 'a';
    string s(1, b); // (no. of times to include that char, char)
    cout << s;

    // converting strings to numbers and vice versa
    string number = "4";
    int num = stoi(number);
    cout << num+5<<endl;
    number = to_string(num + 6);
    cout << number << endl;
    
    // stringstream class:  
    // its like stdin and stdout at one place. 
    // to read from the stream, use ">>" (just like we do for stdin (cin>>))
    // and to write to the stream, use "<<", just like we dor for stdout (cout<<)
    // to clear the stream, use 
    number = "44";
    num = 46;
    stringstream sso;
    sso << num;          
    sso >> number;      // now number ="46", num =46
    cout << number + '3'<<endl;
    
    sso.clear();        // to clear the stringstream, as it contains values.
    number = "44";      // clear may not work effectively sometimes, it is safe to declare a new stream.
    sso << number;
    sso >> num;         // now number ="44", num =44; 
    cout << num + 5<<endl;

    return;
}

void stl_containers(){

    // VECTOR, PAIR, STACK, QUEUE, PRIORITY_QUEUE, DEQUEUE

    // VECTORS
    // Initialisation
    int n=5;
    vector<int> vec(n);             // initialise all elements with zero.
                                    // vec.push_back() will insert an element at n+1 position.
    vector<int> vec(n, 5);          // initialise all elements with 5.
    
    vector <int> vec1;              // no initialisation
    
    // from an array/vector
    vector<int> vec(arr, arr + n);              // from an array
    vector<int> vec(vec1.begin(), vec1.end());  // from another vector 

    // 2D Vectors with user-defined size: 
    int rows = 5, cols = 5;
    vector<vector<int>> matrix(rows);
	vector<int> temp(cols);
	for(int i=0; i<rows; i++){
        matrix[i] = temp;
	}
    //Better:
    vector<vector<int>> vec( rows , vector<int> (cols, 0));
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout << vec[i][j];
        }
    }

    ///////////////////////////
    //     STACKS!!
    // stk.pop() : removes last element, returns nothing
    // stk.top() : removes nothing, returns last element
    // its stk.push(val) not stk.push_back(val) 

    // other general functions of stl containers
    //********************************************************************************************

    // MAP, UNORDERED_MAP; SET, UNORDERED_SET; MULTISET, UNORDERED_MULTISET; 
    
    //MAP
    // MAPS!!
    // while declaring map, every key maybe assumed as initialised with zero. we can directly use map[<new_key>]++;
    // to check if a key exists: use map.count(key). TC= log(n)
    // never use map[unknown_key]. it will create key value pair with pair (unknown_key,0). 
    // if (map[<unknown_key>]== 0) returns true.
    // if (map[<unknown_key>]==-1) returns false.
    // if (map[<unknown_key>]==-1 || map.count(<unknown_key>)) will return true.
    // using if(!map[key]) may return correct answer, but at the same time makes the key for the same and may cause troubles in iteration.	

    // e.g. 
    // if(!check.count(5)) cout<<"hello";
    // if(!check[5]) cout<<"hello";
    // if(!check.count(5)) cout<<"hello";
    // output: hellohello


    //*********************************************************************************************    
    // ITERATORS
    
    // arithmetic operations on iterators is not allowed. (i+3, v.begin()+4 etc.)
    // they can only be incremented or decremented. (i++, i--)
    // However, operations can be done on iterators of vectors, but it is not preferred. 
}

void maths(){

    // mod of negative numbers
    // working of the modulo operator:   a == (a / b * b) + a % b
    // sign of divisor doesn't make any difference. if dividend in negative, remainder will be negative.
    // if(divisor>abs(dividend)) in case of negative dividend and positive divisor, do (divisor + dividend)%divisor 
    // while calculating %mod (10e+7) for negative number: (mod + num )%mod


    // to calculate gcd:
    // let two numbers be x, px+q.
    // as a number 'a' divides both, (px+y)/a is integer, and as x/a is also integer => y/a needs to be integer.
    // => gcd of x,a. 
    // now keep on applying same thing untill q=0.


    // doubles, negatives, absolute values, factorials, pow(x,n), calculating powers, casting between data types (integer to double etc.)
    // abs, ininf

    // floor, ceil and round for integers:
    double d = 34.5;
    int k = floor(d);
    cout << k;
    k = ceil(d);
    cout << k;
    cout << round(d);
}



int main(){

    // c++
    // data_types();
    // arrays();
    // strings();
    stl_containers();
    //maths();
    
    //dsa
    // harre's and lomuto's partition principle
    // MEMORY HACKS!!
	// can store two values in constant space in the form of : ax + b ; where x is known so we can easily find a and b.
	// use the input data (vector, arr etc.) itself to store flags. it will prevent use of additional memory. for e.g, negate the data where required and negate again in the end if you don't want to mess up with original data. 

	// while iterating to keep a track of whether you've visited that particular element before or not, replace the element you are visiting with its negative any other allowed flag. can use ax+b here also.

    // TREES:
	// Inorder traversal: left child, node, right child (go to depth and then print while coming back)
	// preorder traversal: node, left child, right child (keep on printing while going deeper)
	// postorder traversal: left child, right child, node (go to depth and print while coming back) 
    // hack: inorder traversal of a bst is always a sorted array. this can be used to validate, correct etc. a binary tree 

    return 0;
}