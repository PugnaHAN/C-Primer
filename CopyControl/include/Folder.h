#ifndef __FOLDER_H__
#define __FOLDER_H__

#include "common.h"

class Message;
class Folder
{
	friend void swap(Folder&, Folder&);
  public:
	explicit Folder(const std::string& n = std::string("New Folder"));
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
	void remMsg(Message*);
	void addMsg(Message*);

  private:
	std::string name;
	unsigned int folder_id;
	std::set<Message*> msgs;

	unsigned int get_unique_id();

	static unsigned int unique_id;
	static std::set<unsigned int> unused_ids;
};

void swap(Folder&, Folder&);

#endif /* __FOLDER_H__ */
