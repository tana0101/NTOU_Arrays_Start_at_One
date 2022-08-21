/*--------stringstream--------*/
stringstream ss;
• getline(cin, str);
• ss.str("");
• ss.clear();

//實現"切割"以及"型態轉換"
//int_to_string
ss << n; 
ss >> str; 

//string_to_int
ss << str;
ss >> n;

//注意輸入時，cin後的快取問題
cin >> n;
getline(cin, str);  //str = endl
getline(cin, str);  //str = 目標str

//實現"進制轉換"
ss << oct << s;    //以8進制讀入流中
ss << hex << s;    //以16進制讀入流中
ss >> n;        //10進制int型輸出
ss >> s;        //x進制str型輸出