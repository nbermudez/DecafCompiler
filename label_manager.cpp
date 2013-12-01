#include "label_manager.h"

LabelManager::LabelManager() {
	if_count = 0;
	endif_count = 0;
	for_count = 0;
	while_count = 0;
	out_of_while_count = -1;
	out_of_for_count = 0;
	continue_count = 0;
	function_end_count = 0;
}

string LabelManager::getIfLabel() {
	ostringstream out;

	out << "if_label_" << if_count++;

	return out.str();
}

string LabelManager::getEndIfLabel() {
	ostringstream out;

	out << "endif_" << endif_count++;

	return out.str();
}

string LabelManager::getElseLabel() {
	ostringstream out;

	out << "else_label_" << else_count++;

	return out.str();
}

string LabelManager::getContinueLabel() {
	ostringstream out;

	out << "continue_point_" << continue_count++;

	return out.str();
}

string LabelManager::getWhileLabel() {
	ostringstream out;

	out << "while_label_" << while_count++;

	return out.str();
}

string LabelManager::getOutOfWhileLabel() {
	ostringstream out;

	out << "out_of_while_" << out_of_while_count++;
	return out.str();
}

string LabelManager::getForLabel() {
	ostringstream out;

	out << "for_label_" << for_count++;

	return out.str();
}

string LabelManager::getOutOfForLabel() {
	ostringstream out;

	out << "out_of_for_" << out_of_for_count++;

	return out.str();
}

string LabelManager::getTrueLabel() {
	ostringstream out;

	out << "true_" << true_count++;

	return out.str();
}

string LabelManager::getFalseLabel() {
	ostringstream out;

	out << "false_" << false_count++;

	return out.str();
}

string LabelManager::getEndLabel() {
	ostringstream out;

	out << "end_" << end_count++;

	return out.str();
}

string LabelManager::getFunctionEndLabel() {
	ostringstream out;

	out << "function_end_" << function_end_count++;

	return out.str();
}

/************************ Setters ************************/
void LabelManager::pushCurrentWhileLabel(string label) {
	this->whileLabels.push(label);
}

void LabelManager::pushContinuePoint(string label) {
	this->continuePoints.push(label);
}

void LabelManager::pushCurrentForLabel(string label) {
	this->forLabels.push(label);
}

void LabelManager::pushBreakPoint(string label) {
	this->breakPoints.push(label);
}
/************************ Getters ************************/
string LabelManager::getCurrentWhileLabel() {
	return this->whileLabels.top();
}

string LabelManager::getCurrentContinuePoint() {
	return this->continuePoints.top();
}

string LabelManager::getCurrentForLabel() {
	return this->forLabels.top();
}

string LabelManager::getCurrentBreakPoint() {
	return this->breakPoints.top();
}

/************************ Poppers ************************/
void LabelManager::popCurrentWhileLabel() {
	this->whileLabels.pop();
}

void LabelManager::popContinuePoint() {
	this->continuePoints.pop();
}

void LabelManager::popCurrentForLabel() {
	this->forLabels.pop();
}

void LabelManager::popCurrentBreakPoint() {
	this->breakPoints.pop();
}