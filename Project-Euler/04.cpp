


public class euler {
	public static void main(String []args){
		long m=0;
		 for(int i=100;i<10000;i++){
			 for(int j=100;j<10000;j++){
		        long n=j*i;
		     
		        String  temp=String.valueOf(n);
		        String  temp2=temp.toString();
		        boolean e=temp2.equals(new StringBuilder(temp2).reverse().toString()); 
		        if(e && n>m){
		        	m=n;
		        }
			 }
		 }
      System.out.println(m);
  }
}

