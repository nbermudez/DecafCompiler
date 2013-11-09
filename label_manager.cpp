#include "label_manager.h"

LabelManager::LabelManager() {
	if_count = 0;
	for_count = 0;
	while_count = 0;
}

string LabelManager::getIfLabel() {
	ostringstream out;

	out << "if_label_" << if_count++;

	return out.str();
}

string LabelManager::getElseLabel() {
	ostringstream out;

	out << "else_label_" << else_count++;

	return out.str();
}

string LabelManager::getWhileLabel() {
	ostringstream out;

	out << "while_label_" << while_count++;

	return out.str();
}

string LabelManager::getForLabel() {
	ostringstream out;

	out << "for_label_" << for_count++;

	return out.str();
}