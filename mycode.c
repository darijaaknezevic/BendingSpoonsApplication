int cnt = 0; // num of people at the table at the moment
semaphore m = 1, TS = N; // Table Semaphore, counting free space at the table
semaphore second = 0, secondAck = 0; //waiting for the last one

void sitT() {
    wait(TS);
    wait(m);
    cnt++;
    if (cnt == 1) { 
        signal(m); wait(second); signal(secondAck);
    }
    else if (cnt == 2) {
        signal(second); wait(secondAck); signal(m);
    }
    else { 
        signal(m); 
    }
}

void leaveT() {
    wait(m);
    cnt--;
    signal(TS);
    if (cnt == 1) {
         signal(m); wait(second); signal(secondAck); 
    }
    else if (cnt == 0) { 
        signal(second); wait(secondAck); signal(m);
    }
    else { 
        signal(m); 
    }
}