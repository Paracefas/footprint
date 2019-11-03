#ifndef MQSensor_H
#define MQSensor_h

class MQSensor 
{
public:
  MQSensor(unsigned port, double(*getPPM)(double), double RL, double R0) 
    : m_port{ port }, m_getPPM{ getPPM }, m_RL{ RL*1000 }, m_R0{ R0 } {}
  double read()
  {
    int adc_MQ = analogRead(m_port); 
    float voltaje = adc_MQ * (5.0 / 1023.0);
    float Rs = m_RL*((5-voltaje)/voltaje);  
    return m_getPPM(Rs/m_R0);
  }
  ~MQSensor() {}
private:
  unsigned m_port;
  double m_RL, m_R0;
  double (*m_getPPM)(double);  
};

#endif