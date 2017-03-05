/*
 * XMLReader.h
 *
 *  Created on: Feb 28, 2017
 *      Author: abrahamon
 */

#ifndef DATAACCESS_XMLREADER_H_
#define DATAACCESS_XMLREADER_H_

#include "../DataAccess/lib.tinyxml/tinyxml.h"
#include <string>

class XMLReader {
private:
	TiXmlDocument documento;
	TiXmlElement* root;
public:
	XMLReader();
	virtual ~XMLReader();
	void loadXMLFile(std::string pData);
	const char* getParameter(const char* pParameter);
};

#endif /* DATAACCESS_XMLREADER_H_ */
