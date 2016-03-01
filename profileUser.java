package app.deutsche.dbglean;

import android.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

/**
 * Created by rishi on 26/6/15.
 */
public class profileUser extends Fragment {
    public static profileUser newInstance()
    {
        profileUser recSearchFragment=new profileUser();
        return recSearchFragment;
    }
    public profileUser()
    {}
    @Override
    public View onCreateView(LayoutInflater inflater,ViewGroup container,Bundle savedInstanceState)
    {
        View rootView=inflater.inflate(R.layout.fragment_profile_user,container,false);
        return rootView;
    }
}
