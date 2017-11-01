import javax.swing.*;
import java.awt.event.*;
import java.lang.reflect.*;
public class ActionListenerInstaller {
		public static void processAnnotations(Object obj){
				try {
						Class cl = obj.getClass();

						for (Field f : cl.getDeclaredFields()) {
								f.setAccessible(true);
								ActionListenerAnnotation a = f.getAnnotation(ActionListenerAnnotation.class);
								Object fObj = f.get(obj);

								if (a != null && fObj != null && fObj instanceof JButton) {
										Class<? extends ActionListener> listenerClass = a.listener();
										ActionListener al = listenerClass.newInstance();
										JButton jb = (JButton)fObj;
										jb.addActionListener(al);
								}
						}
				} catch(Exception e){
						e.printStackTrace();
				}
		}
}
