import java.util.Scanner;
public class QuickFindUF {


    public static void main(String[] arg)
    {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        QuickFind QF = new QuickFind(N);
        while(input.nextLine()!=null)
        {
            int p = input.nextInt();
            int q = input.nextInt();
            if(!QF.connected(p, q))
            {
                QF.union(p, q);
                System.out.println(p+" "+q);
            }
            else {
                System.out.println(p +" and "+ q+" is connected");
            }
        }
        
        
        



    }
    
}
class QuickFind{
    private int[] id;
    public QuickFind(int N)
    {
        id = new int[N];
        for(int i=0; i<N; i++)
            id[i]=i;
    }
    public boolean connected(int p, int q)
    {
        return id[p]==id[q];
    }
    public void union(int p, int q)
    {
        int pid = id[p];
        int qid = id[q];
        for(int i=0; i<id.length; i++)
            if(id[i]==pid) id[i] = qid;
    }
}