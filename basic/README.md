# Basic
 
## tmux

```cmd
# Ubuntu Linux 安裝 tmux
sudo apt install tmux
```

```cmd
# 執行 tmux
tmux
```

```cmd
# 進入指令模式
Ctrl+b
```

| 常用指令 | 功能 | 
| -------- | -------- | 
| Ctrl+b 再輸入 %  | 垂直分割視窗。| 
| Ctrl+b 再輸入 "  | 水平分割視窗。| 
| Ctrl+b 再輸入 方向鍵  | 切換至指定方向的視窗。| 

  <img src="https://github.com/tana0101/NTOU_Arrays_Start_at_One/blob/main/basic/Print%20Screen/test%20tmux.png?raw=true" alt="Cover" width="80%"/><BR>

參考資料：
https://blog.gtwang.org/linux/linux-tmux-terminal-multiplexer-tutorial/

<br>


## vimrc (Vim's config file)

```cmd
# Ubuntu Linux 安裝 vim
sudo apt-get install vim
```

```cmd
# 移動到家目錄
cd
```

```cmd
# 透過vi建立vimrc
vi .vimrc
```

  <img src="https://github.com/tana0101/NTOU_Arrays_Start_at_One/blob/main/basic/Print%20Screen/set%20vim.png?raw=true" alt="Cover" width="80%"/><BR>

設定vim環境參數
將以下指令複製貼上（Ctrl+Shift+V）

```vim
set nocp nu rnu cul ru ai cin si sta
set sc stal=2 ls=2 so=5 ts=4 sw=4 sts=4 et
set hls sm is ic scs wrap lbr bg=dark
set encoding=utf8
set mouse=a 
filetype plugin indent on
syntax enable
no ; :
no <C-l> :nohl<CR>
au filetype c,cpp ino <F9> <ESC>:w<CR>:!~/run '%'<CR>
au InsertLeave *.cpp write
let leader = '\'
function! Tg()
    s,^\(\s*\)\?,\1// ,e
    s,^\(\s*\)\(// \?\)\{2},\1,e
endfunc
au filetype c,cpp no <leader><leader> :call Tg()<CR>
```

```cmd
# ESC進入指令模式
ESC
# 儲存後退出檔案
:wq
```

  <img src="https://github.com/tana0101/NTOU_Arrays_Start_at_One/blob/main/basic/Print%20Screen/vimrc.png?raw=true" alt="Cover" width="80%"/><BR>

參考資料：
http://wiki.csie.ncku.edu.tw/vim/vimrc
https://github.com/tana0101/NYCU_gAwr_gurA

<br>


## vim ＆ tmux
  <img src="https://github.com/tana0101/NTOU_Arrays_Start_at_One/blob/main/basic/Print%20Screen/test%20coding.png?raw=true" alt="Cover" width="80%"/><BR>

<br>


## Vim (Basic Vim commands)

### 常用
| 指令 | 功能 | 說明 | 
| -------- | -------- | -------- | 
| i          | 插入　　　　　| 進入插入模式| 
| u          | 返回上一步　　| 取代[Ctrl]+z| 
| [Shift]    | 變大寫　　　　| 用於指令輸入| 
| [ESC]      | 回到指令模式　| 取消指令或退出編輯模式| 

### 移動
| 指令 | 功能 | 說明 | 
| -------- | -------- | -------- | 
| gg          | 移到第一行　　| | 
| [Shift] + g | 移到最後一行　| 壓著Shift同時按下g| 
|字數 → [Space]| 向右移動 n 個字元　| 例如:輸入15再按下[Space] 向右移動15個字元| 
|字數 → [Enter]| 向下移動 n 個字元　| 例如:輸入15再按下[Space] 向下移動15個字元| 
|行數 → k      | 向上移動 n 個字元　| 例如:輸入15再按下[Space] 向上移動15個字元| 

### 標記、複製、剪下、貼上
| 指令 | 功能 | 說明 | 
| -------- | -------- | -------- | 
|v           | 標記　　　　| | 
|[Shift] + v | 整行標記　　| 壓著Shift同時按下v| 
|y           | 複製標記內容| 取代[Ctrl]+c| 
|yy          | 複製整行　　| |
|d           | 剪下標記內容| 取代[Ctrl]+x| 
|dd          | 剪下整行　　| |
|p           | 貼上　　　　| 取代[Ctrl]+v|

### 特殊操作

#### 全部排版
```cmd
# 回到第一行
gg
# 標記整行
Shift + v
# 移到最後一行
Shift + g
# 排版
'='
```

參考資料：
https://code.yidas.com/linux-vi-vim-command/

<br>


## Github

### 安裝
```git
sudo apt-get install git-all
```
### 個人資料
```git
# 設定
git config --global user.name "name"
git config --global user.email "youremail@gmail.com"
# 查詢
git config --list
```
 <img src="https://github.com/tana0101/NTOU_Arrays_Start_at_One/blob/main/basic/Print%20Screen/git%20config.png?raw=true" alt="Cover" width="80%"/><BR>
 
### 與github連線
```git
# 查詢
git remote -v
# 設定
git remote add origin <your url>
```

  <img src="https://github.com/tana0101/NTOU_Arrays_Start_at_One/blob/main/basic/Print%20Screen/git%20remote.png?raw=true" alt="Cover" width="80%"/><BR>

### 第一次將repositories存入本地
```git
# https
git clone https://github.com/fukuball/Hello-World.git
# SSH
git clone git@github.com:fukuball/Hello-World.git
```

### 分支

```git
# 建立分支
git branch <branchname>
# 查詢分支
git branch
# 切換分支
git checkout <branch>
# 建立分支並切換
git checkout -b <branch>
# 將目前分支合併至branch
git checkout <branch>
# 將分支刪除
git branch -d <branch>
```

### 上傳與下載
```git
# 加入所有修改內容
git add .
# 此次上傳的描述
git commit -m "message"
# 上傳到origin的main分支
git push -u origin main

# 將修改內容下載到本地
git pull
```

 <img src="https://github.com/tana0101/NTOU_Arrays_Start_at_One/blob/main/basic/Print%20Screen/git%20add.png?raw=true" alt="Cover" width="80%"/><BR>
  <img src="https://github.com/tana0101/NTOU_Arrays_Start_at_One/blob/main/basic/Print%20Screen/git%20push.png?raw=true" alt="Cover" width="80%"/><BR>
  
### 透過Visual Studio Code 取代push & pull

  <img src="https://github.com/tana0101/NTOU_Arrays_Start_at_One/blob/main/basic/Print%20Screen/git%20vscode.png?raw=true" alt="Cover" width="80%"/><BR>

<br>


## Ubuntu

### 修正滾輪速度 --imwhe
https://github.com/twtrubiks/linux-note/tree/master/imwheel-tutorual
```vim
# 速度3比較剛好
None, Up, Button4, 3
None, Down, Button5, 3
```

### 小畫家 --KolourPain

```cmd
sudo apt install kolourpaint4
```

### 執行exe檔案 --Wine

```cmd
sudo apt install wine64
```

### 原生支援
* VSCode
* Discord
* Google Chrome
