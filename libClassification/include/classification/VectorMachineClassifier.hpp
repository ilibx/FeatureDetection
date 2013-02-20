/*
 * VectorMachineClassifier.hpp
 *
 *  Created on: 16.02.2013
 *      Author: Patrik Huber
 */

#pragma once

#ifndef VECTORMACHINECLASSIFIER_HPP_
#define VECTORMACHINECLASSIFIER_HPP_

#include "classification/BinaryClassifier.hpp"
#include "classification/Kernel.hpp"
#include <memory>

using std::shared_ptr;

namespace classification {

/**
 * A classifier that uses some kind of support vectors to classify a feature vector.
 */
class VectorMachineClassifier : public BinaryClassifier
{
public:
	VectorMachineClassifier(void);
	~VectorMachineClassifier(void);

protected:
	shared_ptr<Kernel> kernel;	// TODO unique_ptr? Look up difference... (shame on me)
	float nonlinThreshold;		// b parameter of the vector machine

};

} /* namespace classification */
#endif /* VECTORMACHINECLASSIFIER_HPP_ */
