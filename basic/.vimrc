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
