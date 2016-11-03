#include "Folder.h"
#include "Message.h"

using namespace std;

unsigned int Folder::unique_id = 0;
set<unsigned int> Folder::unused_ids = set<unsigned int>();

unsigned int Folder::get_unique_id()
{
	unsigned int id;
	if(!unused_ids.empty())
	{
		auto it = unused_ids.begin();
		id = *it;
		unused_ids.erase(*it);
	}
	else
		id = ++unique_id;
	return id;
}

Folder::Folder(const string& n):name(n) 
{
    folder_id = get_unique_id();
}

Folder::Folder(const Folder& f):
		name(f.name), msgs(f.msgs), folder_id(f.folder_id)
{
	for(auto m : f.msgs)
		addMsg(m);
}

Folder& Folder::operator=(const Folder& f)
{
	for(auto m : msgs)
		remMsg(m);
	name = f.name;
	msgs = f.msgs;
	for(auto m : f.msgs)
		addMsg(m);
	return *this;
}

void Folder::addMsg(Message* m)
{
	msgs.insert(m);
	m->folders.insert(this);
}

void Folder::remMsg(Message* m)
{
	msgs.erase(m);
	m->folders.erase(this);
}

Folder::~Folder()
{
	for(auto m : msgs)
		remMsg(m);
	unused_ids.insert(folder_id);
}

void swap(Folder& f1, Folder& f2)
{
	using std::swap;
	for(auto m : f1.msgs)
		f1.remMsg(m);
	for(auto m : f2.msgs)
		f2.remMsg(m);

	swap(f1.name, f2.name);
	swap(f1.folder_id, f2.folder_id);
	swap(f1.msgs, f2.msgs);

	for(auto m : f1.msgs)
		f1.addMsg(m);
	for(auto m: f2.msgs)
		f2.addMsg(m);
}
