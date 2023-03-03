# git

## 安装

官网下载安装包https://git-scm.com/默认安装

安装完成后需要设置一下账户，因为git是分布式版本控制系统

```bash
git config user.name "用户名"
git config user.email "邮箱地址"
git config --global user.name "用户名"
git config --global user.email "邮箱地址"
# --global    参数     表示这台计算机上所有的git仓库都会使用这个配置
```

## 创建仓库 repository

```bash
# 创建前先在电脑上找一个合适的位置，创建一个空文件夹

mkdir 目录名  #不要有中文
cd learngit
pwd

# mkdir  命令用来创建文件夹
# pwd  命令用来显示当前目录。

git init    # 将仓库交给git管理    初始化仓库
Initialized empty Git repository in E:/onepost/.git/
# git管理后    目录里会多出一个 .git的隐藏文件夹    这是git来跟踪管理版本库的
```

## 创建文件与编辑保存文件

```bash
# 创建文件与编辑保存文件
vi 文件名    # 进入文件编辑文件
# 编辑完成后    按esc键 输入:wq(不要忘了有一个冒号)，最后按回车保存
```

## 将文件提交到git仓库暂存区

```bash
# 将文件提交到git仓库暂存区
git add readme.txt
git commit -m "提交说明"
# add 添加    commit 说名
# 可以一次 add很多个文件

# ls  和   dir 命令查看当前目录的文件
```

```bash
# 查看仓库当前状态
git status

# 查看difference(之前的改动)
git diff  要查看的文件
```

## 版本回退

```bash
# 版本回退
git log   # 查看历史提交记录    显示的记录由近及远

HEAD    # 表示当前版本
HEAD^   # 上一个版本
HEAD~100    # 上一百个版本

git reset --hard HEAD^    #回退到上一个版本
git reset --mixed HEAD^   #默认回退--mixed可不写
git reset --soft HEAD^/HEAD~1   #  撤销commit
git reset -- HEAD^/HEAD~1   #  撤销commit

git reset --soft HEAD^1   # 撤回最近一次远程提交

cat 文件名    #查看文件内容

# 如果想回到未来的版本
git reset --hard 要回到的那个版本的版本号    # 版本号不必写全能查到就行

# 查看命令历史
git reflog

```

##  工作区和暂存区

```bash
# 工作区和暂存区

git add    #将文件提交到暂存区
git commit  # 提交到版本库
git commit --amend  # 修改已commit的注释信息实现


# 所有任何修改必须经过暂存区才能被提交到仓库中
```

```bash
# 撤销修改
git checkout -- 要撤销修改的文件
# 这个是还没有上传到暂存区时的状态
# 如果已经上传到暂存区了，它只能撤销内容，状态还是已经在暂存区的
```

```bash
# 把暂存区的修改回退到工作区

git reset HEAD 要回退到工作区的文件
# 这个命令把已经提交到暂存区的修改回退到了工作区，当前状态改变了
```

```bash
# 删除文件
rm 要删除的文件
git rm 要删除的文件
```

## 操作远程仓库

```bash
# 远程仓库
# 因为远程仓库之间传输需要加密，所以需要一些设置
# 1.创建 SSH Key

ssh-keygen -t rsa -C "2536977381@QQ.COM"   # 然后一路回车


# 添加远程库
# 登陆GitHub，然后，在右上角找到“Create a new repo”按钮，创建一个新的仓库
# 2. 将本地仓库与远程仓库关联
 git remote add origin 远程地址
# 3.将本地仓库内容推送到远程仓库上    git push
git push -u origin master
# 4.之后只要本地做了修改就可以利用下面的命令提交到远程仓库
git push origin master

```

```bash
# 删除远程库

git remote -v   # 查看远程库信息
git remote rm 文件名    # 删除远程库
# 删除相当于解除本地仓库与远程仓库的联系，远程库本身没有改变

```

```bash
# 从远程库克隆

git clone 远程库地址
```

## 操作分支

```bash
# 查看分支
git branch # 查看当前分支
git branch -a # 查看所有分支
git branch -r # 查看所有远程分支
# 创建分支
git branch 分支名称 # 创建本地分支
git push --set-upstream origin 分支名称 # 创建远程分支
# 删除分支
git branch -d 分支名称 # 删除本地分支
git push origin --delete 分支名称 # 删除远程分支
# 合并分支
git merge 分支名称     # 合并某分支到当前分支
git merge --abort   # 取消合并
# 切换分支
git checkout 分支名称 # 切换到指定分支
git checkout -b 分支名称 # 创建并切换到指定分支
git checkout -b 本地分支名 origin/远程分支名 # 切换远程分支，也可以理解为创建本地分支并拉取远程分支
git switch -c 分支名称     # 新语法创建并切换分支
git switch 分支名称 # 新语法切换到指定分支
# 代码推送
git push --set-upstream origin 分支名 # 将本地分支推送到远程仓库
git pull   # 获取远程最新修改
git rebase master # 合并主干的修改
git checkout .   #  撤回未提交的所有数据
```

```bash

```

