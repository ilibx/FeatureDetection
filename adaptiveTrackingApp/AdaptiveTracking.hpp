/*
 * AdaptiveTracking.hpp
 *
 *  Created on: 19.07.2012
 *      Author: poschmann
 */

#ifndef ADAPTIVETRACKING_HPP_
#define ADAPTIVETRACKING_HPP_

#include "imageio/ImageSource.hpp"
#include "imageio/ImageSink.hpp"
#include "condensation/AdaptiveCondensationTracker.hpp"
#include "condensation/AdaptiveMeasurementModel.hpp"
#include "condensation/MeasurementModel.hpp"
#include "condensation/SimpleTransitionModel.hpp"
#include "condensation/ResamplingSampler.hpp"
#include "condensation/GridSampler.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <memory>
#include <string>
#include <memory>
#include <string>

using namespace imageio;
using namespace condensation;
using cv::Mat;
using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;

class AdaptiveTracking {
public:

	AdaptiveTracking(unique_ptr<ImageSource> imageSource, unique_ptr<ImageSink> imageSink, string svmConfigFile, string negativesFile);
	virtual ~AdaptiveTracking();

	void run();
	void stop();

private:

	static void adaptiveChanged(int state, void* userdata);
	static void samplerChanged(int state, void* userdata);
	static void sampleCountChanged(int state, void* userdata);
	static void randomRateChanged(int state, void* userdata);
	static void scatterChanged(int state, void* userdata);
	static void drawSamplesChanged(int state, void* userdata);

	void initTracking();
	void initGui();
	void drawDebug(Mat& image);

	static const string videoWindowName;
	static const string controlWindowName;

	const string svmConfigFile;
	const string negativesFile;

	unique_ptr<ImageSource> imageSource;
	unique_ptr<ImageSink> imageSink;

	bool running;
	bool paused;
	bool drawSamples;

	unique_ptr<AdaptiveCondensationTracker> tracker;
	shared_ptr<MeasurementModel> staticMeasurementModel;
	shared_ptr<AdaptiveMeasurementModel> adaptiveMeasurementModel;
	shared_ptr<SimpleTransitionModel> transitionModel;
	shared_ptr<ResamplingSampler> resamplingSampler;
	shared_ptr<GridSampler> gridSampler;
};

#endif /* ADAPTIVETRACKING_HPP_ */