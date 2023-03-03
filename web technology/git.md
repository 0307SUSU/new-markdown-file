# git

## 安装

官网下载安装包https://git-scm.com/默认安装

安装完成后需要设置一下账户，因为git是分布式版本控制系统

```bash
git config user.name "用户名"
git config user.email "邮箱地址"
git config --global user.name "用户名"
git config --global user.email "邮箱地址"
# --global    参数     表示这台计算机上所有的git仓库都会使用这个配置，不加此参数表示只为当前仓库配置
```

## 创建本地仓库 repository

```bash
# 创建前先在电脑上找一个合适的位置，创建一个空文件夹

mkdir 目录名  #创建文件夹
cd 目录名  #进入目录
pwd  #显示当前目录。
git init  #将仓库（文件夹/目录）交给git管理    初始化仓库
# git管理后    目录里会多出一个 .git的隐藏文件夹    这是git来跟踪管理版本库的
```

## 创建文件与编辑保存文件

```bash
touch test.js  # 新建文件
vi 文件名  # 进入文件编辑文件
# 编辑完成后    按esc键 输入:wq(不要忘了有一个冒号)，最后按回车保存
```

## 提交文件/工作区&暂存区&本地仓库&远程仓库

```bash
git status  # 查看仓库当前状态
git diff  要查看的文件   # 查看difference(之前的改动)
# ls  和   dir 命令查看当前目录的文件
git checkout -- fileName  # 将文件撤回到最近一次修改的状态
git add 文件名   # 将文件提交到git仓库暂存区
git add --all（-A） # 提交当前目录下所有改动文件到暂存区（会记录删除操作）
git add .  # 提交当前目录下所有改动文件到暂存区（不会记录删除操作）
git commit -m "提交说明"  #提交暂存区的文件到本地仓库
git commit --amend  # 重写上一次的提交信息
```

## 控制版本

```bash
git log   # 查看历史提交记录
git log filename  #查看单个文件历史提交记录
git log --pretty=oneline #以简介形式查看历史提交记录
cat 文件名    #查看文件内容
HEAD    # 表示当前版本
HEAD^   # 上一个版本
HEAD~100    # 上一百个版本
reset  # 重置命令 
git reset --mixed HEAD^ #默认回退--mixed可不写,将暂存区内容回退到工作区
git reset --soft HEAD^/HEAD~1   #  撤销已经commit的修改到暂存区
git reset --hard HEAD^/要回滚的commit id  #回退到上一个版本或指定版本
git reflog  # 查看详细操作历史
```

## 操作分支&仓库&远程仓库

```bash
rm 要删除的文件  #需重新add
git rm 要删除的文件  #需重新commit
```

```bash
#仓库
```

```bash
git remote add origin 远程地址 # 将本地仓库与远程仓库关联
git push -u origin 分支名称# 将本地仓库内容推送到远程仓库上
git clone 仓库地址  #拉取远程仓库到本地
git push --set-upstream origin 分支名称 # 创建远程分支（将本地分支推送到远程仓库）
git push origin --delete 分支名称 # 删除远程分支
git pull   # 获取所有远程分支的最新修改
git remote -v  # 查看远程库信息
git remote rm 文件名  # 删除远程库
# 删除相当于解除本地仓库与远程仓库的联系，远程库本身没有改变
```

```bash
git branch # 查看当前分支
git branch -a # 查看所有分支
git branch -r # 查看所有远程分支
git branch 分支名称 # 创建本地分支
git branch -D 分支名称 # 删除本地分支
git merge 分支名称     # 合并某分支到当前分支
git merge --abort   # 取消合并
git checkout 分支名称 # 切换到指定分支
git checkout -b 分支名称 # 创建并切换到指定分支
git checkout -b 本地分支名 origin/远程分支名 # 切换远程分支，也可以理解为创建本地分支并拉取远程分支
git checkout .   #  撤回未提交的所有数据
git switch -c 分支名称     # 新语法创建并切换分支
git switch 分支名称 # 新语法切换到指定分支
git rebase master # 合并主干的修改
```

