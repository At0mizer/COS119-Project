# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [ COS119 | Project and Portfolio I: Computer Science ]

- **[ Bradley Musinski ]**
- **[ Oct 4, 2026 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ CLS ]: Clear the Screen
- [ PWD ]: Print the "Working Directory"
- [ ls ]: List files and folders
- [ ls -Force ]: List files and folders, including invisible files
- [ ls -Force | Format-Table ]: List all files and folders, in human readable form
- [ cd <folder> ]: Change directory
- [ cd \ ]: Change directory, go to root directory
- [ cd ~ ]: Change directory and go to user home directory
- [ cd .. ]: Change directory, go up one folder level
- [ cd..\.. ]: Change directory, go up two folder levels
- [ cd ~/Desktop ]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ When I typed cd and dragged a folder into PowerShell, it automatically added the folder's full path after the command. After pressing enter, the terminal changed the current directory to that folder ]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[ Local Version CS - stores file version directly on your computer]
[ Centralized Version CS - stores the project and its version history on a centralized server with multiple users connected]
[ Distributed Version CS - gives each user aa complete copy of the repos and its history, allowing work to continue locally and sync with others]

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [ git clone <url> ]: Clone a repository
- [ git config --global user.name "Your Name" ]: Set-up a global user name
- [ git config --global user.email "your email" ]: Set-up a global email address (to match my GitHub account email)
- [ git stattus ]: Shows the current state of your directory and staging area
- [ git add . ]: Add modified files to the next commit
- [ git commit -m "Your Message" ]: Make a commit with a new message
- [ git log ]: Show my commit history
- [ git help ]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

1. Open GitHub and copy the repository URL
2. Open PowerShell
3. Navigate to the folder where you want the repository saved using cd
4. Type git clone followed by the URL
5. Git will download the repository to your computer
6. Use cd to enter the new repos folder
7. Use comands like git pull, git add, git commit, and git push to work with the GitHub 
	

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [Tell Git which files and folders it should not track or upload to the repos. This helps keep unnecessary, temporary, or system-generated files that are not apart of the project]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [.DS_Store is a hidden file that was created by macOS to store folder display settings]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [I would add build folders such as bin/ or obj/ because they contain generated files that can be recreated when the program is built and do not need to be stores in the repos]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[ Research Summary: What resource(s) did you find most helpful this past week and why? ]

**Terminal Commands**  
[Site Address](https://devblogs.microsoft.com/scripting/table-of-basic-powershell-commands/)

**Three Types of Version Control**  
[Site Address](https://git-scm.com/book/en/v2/Getting-Started-About-Version-Control.html)

**Git Commands**  
[Site Address](https://git-scm.com/cheat-sheet)

**Connecting to GitHub using Terminal**  
[Site Address]([https://www.someaddress.com/full/url/](https://docs.github.com/en/repositories/creating-and-managing-repositories/cloning-a-repository))

**Using .gitignore and Why it's Important**  
[Site Address](https://docs.github.com/en/get-started/git-basics/ignoring-files)
