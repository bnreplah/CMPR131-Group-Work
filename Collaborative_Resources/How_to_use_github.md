# How to use Github #

    A breif run down on the uses of github and git

## References ##

Adding ssh-keys to github from gitbash
<https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent>

Git and Git hub crash course:
<https://www.youtube.com/watch?v=SWYqp7iY_Tc>

Git and Github workflow ( for working in teams ):
<https://www.youtube.com/watch?v=oFYyTZwMyAg&t=605s> 

## What is gitbash ##

You may be wondering what is gitbash. Gitbash is a command line utility that is used for managing git from the terminal. Git is a change tracking utility that has the capability to be hosted from a local or private repository. A repoistory is a grouping of files ( archive ).
Using gitbash one is able to easily manage and create folders and files, and push and pull them to the repository. In team collobartion setting, git allows multiple members to work on the same projects and track the changes of the project and merge them when possible.

Another convenient git managment tool is gitkraken. It is free and has a nice graphical interface for managing github and gitlab and most git services.

They all run on the same principles, coming from git. In the video tutorials above is a link to a crash course of git and gitbash which will cover the things mentioned in more depth.

## Cloning ##

Once made a contributor on github to a repository, you can go in and clone the repository into a folder locally on your own machine. Github provides you with 2 methods of doing this, either over ssh or over https.

The link below speaks more about the various selection of remote connection medium.
<https://docs.github.com/en/get-started/getting-started-with-git/about-remote-repositories>

I prefer to use ssh-key usage, otherwise in the current version of git hub, when prompted for a password for the push request, a onetime passcode needs to be provided.

## Using git with git hub ##

Once the repository is cloned on your machine you can `git pull` to get the latest version of the repository branch your in. you can use `git branch branchname` to create a new branch off of the current branch you are in. `git checkout branchname` will switch you over to the other branch, any uncommited changes may be lost. You can use `git add .` to track all new changes made. Following `git add <filename>` or `git add .` you can use `git status` to see the staging status of the files. This will show info about the status of the tracked changes within those files. `git commit -m 'message about commit'` can be used to commit the tracked changes. Following the call to `git commit` above, one can then use `git push` to push the changes to the repository. After one is finished working on a branch and is ready for the branch to merge with the rest of the code, go to the master branch and `git pull` the master branch to get the latest version of the code, and then switch back to the branch you were working on and use `git merge master` to merge your branch with the master branch locally, then still in your working branch add the changes and commit them, then push the ____branch____ to github. In github, you then can browse to your branch and click the `pull request` button. On there you can add some info about your oull request and wait for it to be reviewed and then someone else will merge it with the master branch.