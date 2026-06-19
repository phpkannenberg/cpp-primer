/*
 * Exercise 13.34: Write the Message class as described in this section.
 * 
 * Exercise 13.36: Design and implement the corresponding Folder class. That class
 * should hold a set that points to the Messages in that Folder.
 * 
 * Exercise 13.37: Add members to the Message class to insert or remove a given 
 * Folder* into folders. These members are analogous to Folder's addMsg and
 * remMsg operations.
 */

#include <string>
#include <set>

class Folder;

class Message 
{
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    // constructor (folders is implicitly initialized to the empty set)
    explicit Message(const std::string& str = ""): contents(str) { }
    
    // copy control to manage pointer to this Message
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    
    // add/remove this Message from the specified Folder's set of messages
    void save(Folder&);
    void remove(Folder&);
    
    void addFolder(Folder*);
    void remFolder(Folder*);

private:
    std::string contents;  // message text
    std::set<Folder*> folders;  // Folders that have this Message
    
    // add this Message to the Folders that point to the parameter
    void add_to_Folders(const Message&);
    // remove this Message from every Folder in folders
    void remove_from_Folders();
};

class Folder
{
    friend class Message;
    friend void swap(Folder&, Folder&); 
public:
    // constructor
    Folder() = default;
    
    // copy control
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    
    void addMsg(Message*);
    void remMsg(Message*);
    
private:
    std::set<Message*> messages;
    
    void add_to_Messages(const Folder&);
    void remove_from_Messages();
};

void Message::save(Folder& f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message& m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
    folders.clear();
}

Message::Message(const Message& m): contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

Message::~Message()
{
    remove_from_Folders();
}

Message& Message::operator=(const Message& rhs)
{
    if (this != &rhs) {
        remove_from_Folders();
        contents = rhs.contents;
        folders = rhs.folders;
        add_to_Folders(rhs);
    }
    return *this;
}

void swap(Message& lhs, Message& rhs)
{
    using std::swap;
    
    // remove pointers to each Message from their (original) respective Folder
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
        
    // swap the contents and Folder pointer sets
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    
    // add pointers to each Message to their (new) respective Folders
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

void Message::addFolder(Folder* f)
{
    folders.insert(f);
}

void Message::remFolder(Folder* f)
{
    folders.erase(f);
}

Folder::Folder(const Folder& m): messages(m.messages)
{
    add_to_Messages(m);
}

Folder::~Folder()
{
    remove_from_Messages();
}

Folder& Folder::operator=(const Folder& rhs)
{
    if (this != &rhs) {
        remove_from_Messages();
        messages = rhs.messages;
        add_to_Messages(rhs);
    }
    return *this;
}

void Folder::add_to_Messages(const Folder& f)
{
    for (auto m : f.messages)
        m->addFolder(this);
}

void Folder::remove_from_Messages()
{
    for (auto m : messages)
        m->remFolder(this);
    messages.clear();
}

void Folder::addMsg(Message* m) 
{ 
    messages.insert(m); 
}

void Folder::remMsg(Message* m) 
{ 
    messages.erase(m); 
}

void swap(Folder& lhs, Folder& rhs)
{
    using std::swap;
    
    for (auto m : lhs.messages)
        m->remFolder(&lhs);
    for (auto m : rhs.messages)
        m->remFolder(&rhs);
        
    swap(lhs.messages, rhs.messages);
    
    for (auto m : lhs.messages)
        m->addFolder(&lhs);
    for (auto m : rhs.messages)
        m->addFolder(&rhs);
}
