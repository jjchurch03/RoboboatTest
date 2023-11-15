# Original Python code used by the 2022 RoboBoat team

Written by Hannah Meisner
  
Code comments by Sierra Barbee

## Needed packages
- sys
- numpy as np
- argparse
- torch
- cv2
- pyzed.sl as sl
- torch.backends.cudnn as cudnn

## Table of Contents
- coordinates.txt
- detector.py
- exp13best.pt
- MainControl.py: defines parameters for thrusters, identifying red and green bouys and their centerpoint, navigating to centerpoint, and motor testing parameters
- object_detection.py
- yolo5m.pt.1
