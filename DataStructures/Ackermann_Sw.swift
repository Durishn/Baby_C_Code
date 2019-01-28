import Foundation

let ALGLOOPNUM = 50

func Helper(x: Int, y: Int, algNum: Int){

    var timeList = [Double]()
    var timeAv = Double()

    for i in 0..<algNum {

        let t2 = CFAbsoluteTimeGetCurrent()

        quicksort(&listBuff, first: 0, last: alist.count-1)

        timeList.append(CFAbsoluteTimeGetCurrent() - t2)
        timeAv += timeList[i];

        print("Algorithm Time: ", timeList[i])
    }

    timeAv /= Double(algNum)
    print("\nAverage Algorithm Time: ", timeAv)
    //print(listBuff)
}

func ackermann(x: Int, y: Int) {
    if x < 0 || y<0 {
        return -1;
    }
    if x == 0 {
        return y+1;
    }
    if y == 0 {
        return ackermann(x-1,1);
    }
    else {
        return ackermann(x-1, ackermann(x,y-1));
    }
}

if Process.arguments.count != 3 {
    print("ERROR: Include an integer")
    exit(0)
}

Helper(int(Process.arguments[1]), int(Process.arguments[2])algNum: ALGLOOPNUM)


