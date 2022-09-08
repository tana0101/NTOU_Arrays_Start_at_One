// build
scc.init(2*m);
for(i=0;i<m;i++){ //所有點比較
  for(j=i+1;j<m;j++){
    if(graph[i].x == graph[j].x){ //同一行
      // m中的2個控制
      // (x or y) x->!y, y->!x -> !x = x+m
      if(abs(graph[i].y - graph[j].y)<=2*r){ // light
          // x or y
          scc.addEdge(i,j+m); 
          scc.addEdge(j,i+m);
      }
    }
    else if(graph[i].y == graph[j].y){ //同一列
      if(abs(graph[i].x - graph[j].x)<=2*r){ // light
          // !x or !y
          scc.addEdge(i+m,j); 
          scc.addEdge(j+m,i);
      }
    }
  }
}
// solve
scc.solve();
for(i=0;i<m;i++){
  if(scc.bln[i] == scc.bln[i+m]){
      cout << "NO\n";
      return 0;
  }
}
cout << "YES\n";