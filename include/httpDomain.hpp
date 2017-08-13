#ifndef _HTTP_DOMAIN_HPP_
#define _HTTP_DOMAIN_HPP_

#include <common.hpp>
#include <httpPath.hpp>
#include <httpReply.hpp>
#include <httpRequest.hpp>

class httpDomain {
   public:
	httpDomain (string domainName);
	httpDomain () : httpDomain ("localhost"){};
	~httpDomain ();

	// inline methods
	inline string getDomainName () {
		return this->domainName;
	}
	inline void setDomainName (string domainName) {
		this->domainName = domainName;
	}

	inline void addPath (httpPath &ph) {
		availablePaths.insert (ph);
	}
	inline void processPath (string &sph, httpRequest &request, httpReply &reply) {
		return this->processPath (httpPath (sph), request, reply);
	}
	void processPath (httpPath &ph, httpRequest &request, httpReply &reply);

   protected:
   private:
	string domainName;
	set<httpPath> availablePaths;
};

#endif