void parseTnput(int r,int c,stromg s){
  if(isdigital(s[0])){
    table[r][c].type = NUMBER;
    table[r][c].val = stod(s);//stod可以将字符串转换为浮点数
  }else{
    string typeStr = s.substr(0,3);
    if(typeStr =="SUM")
      table[r][c].type = SUM;
    else if(typeStr == "AVG")
      table[r][c] = AVG;
    else if(typeStr == "STD")
      table[r][c] = STD;
    size_t start = s.find('(') + 1;
    size_t comma1 = s.find(',',start);
    size_t colon = s.find(':', comma1);
    size_t comma2 = s.find(',', colon);
    size_t end = s.find(')');
    table[r][c].x1 = stoi(s.substr(start,comma1 - start)) - 1;//stoi将字符转换为整数
    table[r][c].y1 = stoi(s.substr(comma1 + 1, colon - (comma1 + 1))) - 1;
    table[r][c].x2 = stoi(s.substr(colon + 1, comma2 - (colon + 1))) - 1;
    table[r][c].y2 = stoi(s.substr(comma2 + 1, end - (comma2 + 1))) - 1;
  }
}
