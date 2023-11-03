#ifdef big_brain__msg__YOLOv5Detection_hpp
#define big_brain__msg__YOLOv5Detection_hpp

#include <string>
#include <vector>

struct YOLOv5Detection
{
    std::string frame_id;  // Frame ID associated with the detection
    std::vector<std::string> object_classes;  // Detected object classes
    std::vector<float> object_scores;  // Confidence scores for detected objects
    std::vector<float> object_bounding_boxes;  // Bounding boxes (x, y, width, height) for detected objects
    std::vector<float> object_positions; //3D positions of detected objects in world coord
    std::vector<float> object_orientations; //Orientations of detected objs
};

#endif