# Linux Tips

## oh my zsh 
step 1: 按照网上的教程弄一下
step 2: 将anaconda3的路径写到～/.zshrc中去

## apt

### `apt-get`: download & install software
```
sudo apt-get install meld
```


### `apt-cache`: search a package by name

```
apt-cache search git
```

## alias

how to set a alias forever
```
sudo gedit ~/.bashrc
```
find the following sentence  
```
#some more ls aliases
```
add what you want change into the next line, for example
```
alias git_ac='git add -A; git commit -m'
```
save and close the file, then reload the file
```
source ~/.bashrc
```
Input test command
```
alias
```
you can find the alias you add, and you can use it even if it starts again.

Find some things
```
dpkg 'name' | grep -i 'describtion'
nm 'name' | more
locate 文件名
```





