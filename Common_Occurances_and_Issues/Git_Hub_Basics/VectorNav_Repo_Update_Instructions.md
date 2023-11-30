# Repo Implementation with established repo without issue

Hi there! If you are here then it has been a few months since the repo for vectornav GPS was updated. This guide will help you do this with general guidance. I expect the project to change a bit so I will not be using exact names for folders.

If things are not working please go down to common issues underneath Instructions. If you notice anything that may become issues/no longer are as this project evolves please update this section

This is based on the Capstone 2023-2024 group specs as of right now
  - Ubuntu 20.04
  - ROS2: Foxy version

## Instructions

1. Clone the vectornav repo to your local host
  - You are going to want to do this temporary cloning in your home folder for ease of location and for your sanity further down the road
  - `git clone https://github.com/dawonn/vectornav.git -b ros2`
2. Create a new branch for implmentation
  - This will be a temporary branch in the temporary repo
  -`git checkout -b integrate-forked`
3. Archive this branch
  - `git archive --format=tar.gz --prefix=path/to/forked-repo/ -o forked-repo.tar.gz HEAD`
  - Replace path/to/forked-repo with the desired subdirectory within your ROS 2 workspace
    -This will dictate the name of this folder so keep this in mind
4. Extract the archive into the working ROS2 workspace within our repo
  -`tar -xzf forked-repo.tar.gz -C path/to/ros2_ws/src/`
  -Replace path/to/ros2_ws with the path to your ROS 2 workspace source folder
5. Add, Commit, and Push
  - 'cd ~/name_of_repo_for_capstone_here`
  - `git add .`
  - `git commit -m "Integrate forked repository into ROS 2 workspace"`
  - `git push`
6. Clean
  - `rm forked-repo.tar.gz`

## Common Issues

- Having to auth for push?
  - [go here for gh help](Common_Occurances_and_Issues/Git_Hub_Basics/Repo_Push_and_Pull.md)
- Having issues with message files (such as cannot locate/work with gemometry (insert rest of name here).hpp)
  -With foxy you need to go into the specified file where this line is located and change the name to end with .h
