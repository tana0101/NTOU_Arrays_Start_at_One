stringstream ss;
getline(cin, str);
ss.str("");
ss.clear();
ss << oct << s;    //以8進制讀入流中
ss << hex << s;    //以16進制讀入流中
ss >> n;        //10進制int型輸出
ss >> s;        //x進制str型輸出