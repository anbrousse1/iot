#ifndef MYXBEE_H
#define MYXBEE_H

class myXbee
{
public:
    myXbee(String myni);
    String sendConfiguration(String conf,bool userCR, bool b);
    String checkResponse(bool b);
    bool configureNetwork();
    bool configureCoordinator();
    bool configureAuto();
    bool configureAutoFor1Card(String ATDH, String ATDL,String key);
    String read();
    void send(String val);
private :
    String ni;
};

#endif // MYXBEE_H
