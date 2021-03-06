/*
Author : Raghav Jethliya & Shivani Baldwa  from MCUT,Taiwan
Guidance by- Professor Chuang Jan Chang from MCUT Taiwan
15th June-2020
 */

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/calib3d/calib3d.hpp"

#include <iostream>	// Stands for input output stream, used to invoke functions like cout,cin in C++ program
#include <ctype.h>	// It is a header file in C/C++ which contains functions for character handling 
#include <algorithm> 	// for copy
#include <iterator> 	// for ostream_iterator
#include <vector>	//  Vectors are sequence containers representing arrays that can change in size.
#include <ctime>	// The ctime() function in C++ converts the given time since epoch to a calendar local time.
#include <sstream>
#include <fstream>
#include <string>

using namespace cv;
using namespace std;
bool renderFeatures = false ;
class mono_vo 
{

public:
	mono_vo(string name);
	double getAbsoluteScale(int frame_id, int sequence_id, double z_cal); 	//To calculate scale value.
	void featureTracking(Mat img_1, Mat img_2, vector<Point2f>& points1, vector<Point2f>& points2, vector<uchar>& status);  // Feature tracking for images
	void featureDetection(Mat img_1, vector<Point2f>& points1);		// Detecting feature points between corresponding images.
	void init(Point txtPos, Point trajPos, Scalar color, double trajscale);
	void runOneFrame(Mat Frame, Mat Traj);
	int runAll();
	~mono_vo();

private:    

	string Name, Name1, Name2, Name3, Name4;  // This variables help in storing the values which is shown in trajectory window.
	int numFrame = 0;
	Mat img_1, img_2;
	Mat R_f, t_f;			 //the final rotation and tranlation vectors
	double scale;
	char text[100];
	char Z[100];
	char Frontview[100];
	char Leftview[100];
	char Rightview[100];
	String text1 = "White color: Ground Truth";
	String text2 = "Red color: Front View";
	String text3 = "Green color: Left View";
	String text4 = "Blue color: Right View";

	int fontFace = FONT_HERSHEY_PLAIN;
	double fontScale = 1;
	int thickness = 1;
	Point textOrg, trajOrg, textZoom, textFront, textLeft, textRight, textOrg1, textOrg2, textOrg3, textOrg4;
	vector<Point2f> points1, points2;        //vectors to store the coordinates of the feature points
	vector<uchar> status;
	double focal;
	Point2d pp;				// Principal Point
	Mat E, R, t, mask;			//Essential Matrix, Rotation Matrix, Translation matrix.  
	Mat prevImage;				// Previous image
	Mat currImage;				// Current image
	vector<Point2f> prevFeatures, currFeatures;
	Mat traj;
	Scalar trajColor;
	double trajScale = 1;
	char filename[100];

};


