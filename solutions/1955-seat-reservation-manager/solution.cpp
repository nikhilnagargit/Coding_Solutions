class SeatManager {
public:
    set<int> Seats;
    SeatManager(int n) {
        Seats = set<int>();
        for(int i=1;i<=n;i++){
            Seats.insert(i);
        }
    }

    int reserve() {
        int seat ;
        auto it = Seats.begin();
        seat = *it;
         Seats.erase(it);
         return seat;
    }
    
    void unreserve(int seatNumber) {
        Seats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
