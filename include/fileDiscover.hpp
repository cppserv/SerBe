#ifndef _FILE_DISCOVER_HPP_
#define _FILE_DISCOVER_HPP_

#include <common.hpp>
#include <httpDomain.hpp>
#include <regex>

class fileDiscover {
   public:
	fileDiscover (shared_ptr<httpDomain> hdom);
	~fileDiscover ();

	void explorePath (string basePath, string systemBasePath);

   protected:
   private:
	shared_ptr<httpDomain> hdom;
	regex indexRegex;  // default: index.htm[l]
};

#endif